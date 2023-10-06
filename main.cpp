#include <iostream>
#include <string>
#include <cstring>
#include <json/json.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <json/json.h>
#include "MagicCub.h"
#include <thread>

const int PORT = 6063;

void handleClient(int clientSocket) {
	char buffer[1024] = {0};
	ssize_t bytesRead;

	while (true) {
		// 读取客户端发送的JSON消息
		memset(buffer, 0, sizeof(buffer));

		bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (bytesRead <= 0) {
			break; // 连接关闭或发生错误，退出处理
		}

		std::cout << buffer << std::endl;

		MagicCub m;

		std::string famual = MagicCub::generateCubeScramble();

		m.Disrupt(famual);
		m.Hide();
		m.ToJson();

		// 回显JSON消息给客户端
		Json::Value root = m.ToJson();
		Json::FastWriter writer;

		std::string jsonstr = writer.write(root);

		char jsonBufer[1024] = { 0 };
		memcpy(jsonBufer, jsonstr.c_str(), jsonstr.size());

		send(clientSocket, jsonBufer, strlen(jsonBufer) + 1, 0);

		std::cout << root.toStyledString() << std::endl;
	}

	close(clientSocket);
}

int main() {
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(serverSocket, 5);

	std::cout << "Server listening on port " << PORT << std::endl;

	while (true) {
		struct sockaddr_in clientAddr;
		socklen_t clientAddrLen = sizeof(clientAddr);
		int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);

		if (clientSocket < 0) {
			std::cerr << "Error accepting client connection." << std::endl;
			continue;
		}
	
		// 使用新线程处理客户端连接
		std::thread(handleClient, clientSocket).detach();
	}

	close(serverSocket);

	return 0;
}