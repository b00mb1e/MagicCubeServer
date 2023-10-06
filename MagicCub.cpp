#include "MagicCub.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h>
MagicCub::MagicCub()
{
	
	
	FrontFace = "RRRRRRRRR";
	BackFace = "OOOOOOOOO";
	LeftFace = "BBBBBBBBB";
	RightFace = "GGGGGGGGG";
	TopFace = "YYYYYYYYY";
	BottomFace = "WWWWWWWWW";
	Formula = "";
	UpdataHide();

	InitBlock();

	isHide = false;
	isDisrupt = false;

	isMatchCenter = false;
	isCor = false;
	isPri = false;

}
MagicCub::MagicCub(std::string formula)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	InitBlock();

	isHide = false;

	isMatchCenter = false;
	isCor = false;
	isPri = false;


	Disrupt(formula);


}
std::string MagicCub::getformula()
{
	return Formula;
}

void MagicCub::Rotate(std::string& face)
{
	char g[3][3];
	for (int i = 0; i < face.size(); i++)
		g[i / 3][i % 3] = face[i];

	for (int i = 0; i < 3; i++)
		std::swap(g[0][i], g[2][i]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < i; j++)
			std::swap(g[i][j], g[j][i]);

	for (int i = 0; i < face.size(); i++)
		face[i] = g[i / 3][i % 3];
}

void MagicCub::Uop()
{
	Rotate(TopFace);

	std::string temp1 = FrontFace.substr(0, 3);

	std::string temp2 = LeftFace.substr(0, 3);

	std::string temp3 = BackFace.substr(6);

	std::string temp4 = RightFace.substr(0, 3);




	for (int i = 0; i < 3; i++)
		FrontFace[i] = temp4[i];
	for (int i = 0; i < 3; i++)
		LeftFace[i] = temp1[i];
	for (int i = 6, k = 2; i < 9; i++)
		BackFace[i] = temp2[k--];
	for (int i = 0, k = 2; i < 3; i++)
		RightFace[i] = temp3[k--];
}

void MagicCub::uop()
{
	Uop();
	Uop();
	Uop();
}

void MagicCub::Dop()
{
	Rotate(BottomFace);
	std::string temp1 = FrontFace.substr(6);
	std::string temp2 = RightFace.substr(6);
	std::string temp3 = BackFace.substr(0, 3);
	std::string temp4 = LeftFace.substr(6);

	for (int i = 6, k = 0; i < 9; i++)
		FrontFace[i] = temp4[k++];
	for (int i = 6, k = 0; i < 9; i++)
		RightFace[i] = temp1[k++];
	for (int i = 0, k = 2; i < 3; i++)
		BackFace[i] = temp2[k--];
	for (int i = 6, k = 2; i < 9; i++)
		LeftFace[i] = temp3[k--];
}
void MagicCub::dop()
{
	Dop();
	Dop();
	Dop();
}

void MagicCub::Lop()
{
	Rotate(LeftFace);



	std::string temp1 = "";
	for (int i = 0; i < FrontFace.size(); i += 3)
		temp1 += FrontFace[i];

	std::string temp2 = "";
	for (int i = 0; i < BottomFace.size(); i += 3)
		temp2 += BottomFace[i];


	std::string temp3 = "";
	for (int i = 0; i < BackFace.size(); i += 3)
		temp3 += BackFace[i];


	std::string temp4 = "";
	for (int i = 0; i < TopFace.size(); i += 3)
		temp4 += TopFace[i];



	for (int i = 0, k = 0; i < FrontFace.size(); i += 3)
		FrontFace[i] = temp4[k++];

	for (int i = 0, k = 0; i < BottomFace.size(); i += 3)
		BottomFace[i] = temp1[k++];

	for (int i = 0, k = 0; i < BackFace.size(); i += 3)
		BackFace[i] = temp2[k++];

	for (int i = 0, k = 0; i < TopFace.size(); i += 3)
		TopFace[i] = temp3[k++];


}
void MagicCub::lop()
{
	Lop();
	Lop();
	Lop();
}

void MagicCub::Rop()
{
	Rotate(RightFace);
	std::string temp1 = "";
	for (int i = 2; i < FrontFace.size(); i += 3)
		temp1 += FrontFace[i];
	std::string temp2 = "";
	for (int i = 2; i < TopFace.size(); i += 3)
		temp2 += TopFace[i];
	std::string temp3 = "";
	for (int i = 2; i < BackFace.size(); i += 3)
		temp3 += BackFace[i];
	std::string temp4 = "";
	for (int i = 2; i < BottomFace.size(); i += 3)
		temp4 += BottomFace[i];



	for (int i = 2, k = 0; i < FrontFace.size(); i += 3)
		FrontFace[i] = temp4[k++];

	for (int i = 2, k = 0; i < TopFace.size(); i += 3)
		TopFace[i] = temp1[k++];

	for (int i = 2, k = 0; i < BackFace.size(); i += 3)
		BackFace[i] = temp2[k++];

	for (int i = 2, k = 0; i < BottomFace.size(); i += 3)
		BottomFace[i] = temp3[k++];

}
void MagicCub::rop()
{
	Rop();
	Rop();
	Rop();
}

void MagicCub::Fop()
{
	Rotate(FrontFace);
	std::string temp1 = "";
	for (int i = 2; i < LeftFace.size(); i += 3)
		temp1 += LeftFace[i];

	std::string temp2 = "";
	temp2 = TopFace.substr(6);

	std::string temp3 = "";
	for (int i = 0; i < RightFace.size(); i += 3)
		temp3 += RightFace[i];

	std::string temp4 = "";
	temp4 = BottomFace.substr(0, 3);

	for (int i = 2, k = 0; i < LeftFace.size(); i += 3)
		LeftFace[i] = temp4[k++];

	for (int i = 6, k = 2; i < 9; i++)
		TopFace[i] = temp1[k--];

	for (int i = 0, k = 0; i < RightFace.size(); i += 3)
		RightFace[i] = temp2[k++];

	for (int i = 0, k = 2; i < 3; i++)
		BottomFace[i] = temp3[k--];

}

void MagicCub::fop()
{
	Fop();
	Fop();
	Fop();
}

void MagicCub::Bop()
{
	Rotate(BackFace);

	std::string temp1 = TopFace.substr(0, 3);

	std::string temp2 = "";
	for (int i = 0; i < LeftFace.size(); i += 3)
		temp2 += LeftFace[i];

	std::string temp3 = BottomFace.substr(6);




	std::string temp4 = "";
	for (int i = 2; i < RightFace.size(); i += 3)
		temp4 += RightFace[i];


	for (int i = 0, k = 0; i < 3; i++)
		TopFace[i] = temp4[k++];
	for (int i = 0, k = 2; i < LeftFace.size(); i += 3)
		LeftFace[i] = temp1[k--];
	for (int i = 6, k = 0; i < 9; i++)
		BottomFace[i] = temp2[k++];
	for (int i = 2, k = 2; i < RightFace.size(); i += 3)
		RightFace[i] = temp3[k--];


}

void MagicCub::bop()
{
	Bop();
	Bop();
	Bop();
}

void MagicCub::Disrupt(const std::string formula)
{

	isDisrupt = true;


	for (int i = 0; i < formula.size(); i++)
	{
		char c = formula[i];

		switch (c)
		{
		case 'U':
			Uop();
			break;
		case 'u':
			uop();
			break;
		case 'D':
			Dop();
			break;
		case 'd':
			dop();
			break;
		case 'L':
			Lop();
			break;
		case 'l':
			lop();
			break;
		case 'R':
			Rop();
			break;
		case 'r':
			rop();
			break;
		case 'F':
			Fop();
			break;
		case 'f':
			fop();
			break;
		case 'B':
			Bop();
			break;
		case 'b':
			bop();
			break;
		default:
			break;
		}

	}

	this->Formula += formula;

	UpdataHide();
}

void MagicCub::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << FrontFace_H[i * 3 + j];

		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << RightFace_H[i * 3 + j];

		std::cout << std::endl;

	}

}

void MagicCub::UpdataHide()
{
	FrontFace_H = FrontFace;
	BackFace_H = BackFace;
	LeftFace_H = LeftFace;
	RightFace_H = RightFace;
	TopFace_H = TopFace;
	BottomFace_H = BottomFace;
}

void MagicCub::InitBlock()
{
	//初始化角块
	CorBlock[0].a = &FrontFace_H[0];
	CorBlock[0].b = &LeftFace_H[2];
	CorBlock[0].c = &TopFace_H[6];

	CorBlock[1].a = &RightFace_H[0];
	CorBlock[1].b = &FrontFace_H[2];
	CorBlock[1].c = &TopFace_H[8];

	CorBlock[2].a = &RightFace_H[2];
	CorBlock[2].b = &TopFace_H[2];
	CorBlock[2].c = &BackFace_H[8];

	CorBlock[3].a = &TopFace_H[0];
	CorBlock[3].b = &LeftFace_H[0];
	CorBlock[3].c = &BackFace_H[6];

	CorBlock[4].a = &BottomFace_H[0];
	CorBlock[4].b = &FrontFace_H[6];
	CorBlock[4].c = &LeftFace_H[8];

	CorBlock[5].a = &BottomFace_H[2];
	CorBlock[5].b = &RightFace_H[6];
	CorBlock[5].c = &FrontFace_H[8];

	CorBlock[6].a = &BackFace_H[2];
	CorBlock[6].b = &BottomFace_H[8];
	CorBlock[6].c = &RightFace_H[8];

	CorBlock[7].a = &BackFace_H[0];
	CorBlock[7].b = &LeftFace_H[6];
	CorBlock[7].c = &BottomFace_H[6];

	//初始化棱块

	PriBlock[0].a = &FrontFace_H[1];
	PriBlock[0].b = &TopFace_H[7];

	PriBlock[1].a = &RightFace_H[1];
	PriBlock[1].b = &TopFace_H[5];

	PriBlock[2].a = &TopFace_H[1];
	PriBlock[2].b = &BackFace_H[7];

	PriBlock[3].a = &LeftFace_H[1];
	PriBlock[3].b = &TopFace_H[3];

	PriBlock[4].a = &FrontFace_H[3];
	PriBlock[4].b = &LeftFace_H[5];

	PriBlock[5].a = &RightFace_H[3];
	PriBlock[5].b = &FrontFace_H[5];

	PriBlock[6].a = &RightFace_H[5];
	PriBlock[6].b = &BackFace_H[5];

	PriBlock[7].a = &BackFace_H[3];
	PriBlock[7].b = &LeftFace_H[3];

	PriBlock[8].a = &BottomFace_H[1];
	PriBlock[8].b = &FrontFace_H[7];

	PriBlock[9].a = &BottomFace_H[5];
	PriBlock[9].b = &RightFace_H[7];

	PriBlock[10].a = &BackFace_H[1];
	PriBlock[10].b = &BottomFace_H[7];

	PriBlock[11].a = &BottomFace_H[3];
	PriBlock[11].b = &LeftFace_H[7];



	CntBlock[0].a = &TopFace_H[4];
	CntBlock[0].matchidx = 5;


	CntBlock[1].a = &FrontFace_H[4];
	CntBlock[1].matchidx = 3;


	CntBlock[2].a = &RightFace_H[4];
	CntBlock[2].matchidx = 4;

	CntBlock[3].a = &BackFace_H[4];
	CntBlock[3].matchidx = 1;

	CntBlock[4].a = &LeftFace_H[4];
	CntBlock[4].matchidx = 2;


	CntBlock[5].a = &BottomFace_H[4];
	CntBlock[5].matchidx = 0;

}

std::string MagicCub::generateCubeScramble()
{
	std::string OpString[] = { "U", "u", "D", "d", "R", "r", "L", "l", "F", "f", "B", "b" };
	std::string scramble = "";

	auto currentTime = std::chrono::high_resolution_clock::now();
	auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();
	std::seed_seq seed{ static_cast<unsigned int>(timestamp) };
	std::mt19937 generator(seed);

	int scrambleLength = generator() % 20 + 1;

	for (int i = 0; i < scrambleLength; ++i)
		scramble += OpString[generator() % 12];

	return scramble;

}

void MagicCub::reset()
{

	FrontFace = "RRRRRRRRR";
	BackFace = "OOOOOOOOO";
	LeftFace = "BBBBBBBBB";
	RightFace = "GGGGGGGGG";
	TopFace = "YYYYYYYYY";
	BottomFace = "WWWWWWWWW";
	Formula = "";
	UpdataHide();

	isHide = false;
	isDisrupt = false;


	isMatchCenter = false;
	isCor = false;
	isPri = false;
}

void MagicCub::HideCenter()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();
	std::seed_seq seed{ static_cast<unsigned int>(timestamp) };
	std::mt19937 generator(seed);
	
	int num = 0;

	while (num < CenterColorNum)
	{
		int idx = generator() % CenterBlockNum;
		char c = *(CntBlock[idx].a);
		int midx = CntBlock[idx].matchidx;

		if (c == 'X') continue;

		if ((*(CntBlock[midx].a) == 'X') && isMatchCenter) continue;

		*(CntBlock[idx].a) = 'X';

		if (*(CntBlock[midx].a) == 'X') isMatchCenter = true;

		num++;

	}
}

void MagicCub::HideCor()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();
	std::seed_seq seed{ static_cast<unsigned int>(timestamp) };
	std::mt19937 generator(seed);
	
	int num = 0;

	while (num < CornerColorNum)
	{
		int idx = generator() % CornerBlockNum;
		int slt = generator() % 3;

		if (slt == 0)
		{
			if (*(CorBlock[idx].a) == 'X') continue;

			if (isCor && *(CorBlock[idx].b) == 'X' && *(CorBlock[idx].c) == 'X') continue;


			*(CorBlock[idx].a) = 'X';

			if (*(CorBlock[idx].b) == 'X' && *(CorBlock[idx].c) == 'X') isCor = true;

			num++;

		}
		else if (slt == 1)
		{
			if (*(CorBlock[idx].b) == 'X') continue;

			if (isCor && *(CorBlock[idx].a) == 'X' && *(CorBlock[idx].c) == 'X') continue;


			*(CorBlock[idx].b) = 'X';

			if (*(CorBlock[idx].a) == 'X' && *(CorBlock[idx].c) == 'X') isCor = true;

			num++;
		}
		else
		{
			if (*(CorBlock[idx].c) == 'X') continue;

			if (isCor && *(CorBlock[idx].b) == 'X' && *(CorBlock[idx].a) == 'X') continue;


			*(CorBlock[idx].c) = 'X';

			if (*(CorBlock[idx].b) == 'X' && *(CorBlock[idx].a) == 'X') isCor = true;

			num++;
		}

	}
}

void MagicCub::HidePri()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime.time_since_epoch()).count();
	std::seed_seq seed{ static_cast<unsigned int>(timestamp) };
	std::mt19937 generator(seed);
	
	int num = 0;

	while (num < PrismaticColorNum)
	{
		int idx = generator() % PrismaticBlockNum;
		int slt = generator() % 2;

		if (slt == 0)
		{
			if (*(PriBlock[idx].a) == 'X') continue;

			if (isPri && *(PriBlock[idx].b) == 'X') continue;

			*(PriBlock[idx].a) = 'X';

			if (*(PriBlock[idx].b) == 'X') isPri = true;

			num++;


		}
		else
		{
			if (*(PriBlock[idx].b) == 'X') continue;

			if (isPri && *(PriBlock[idx].a) == 'X') continue;

			*(PriBlock[idx].b) = 'X';

			if (*(PriBlock[idx].a) == 'X') isPri = true;

			num++;
		}



	}
}

void MagicCub::Hide()
{
	HideCenter();
	HideCor();
	HidePri();
}

Json::Value MagicCub::ToJson()
{
	Json::Value root;
	Json::Value surface;
	surface["Front"] = FrontFace;
	surface["Back"] = BackFace;
	surface["Left"] = LeftFace;
	surface["Right"] = RightFace;
	surface["Top"] = TopFace;
	surface["Bottom"] = BottomFace;
	Json::Value surface_H;
	surface_H["Front"] = FrontFace_H;
	surface_H["Back"] = BackFace_H;
	surface_H["Left"] = LeftFace_H;
	surface_H["Right"] = RightFace_H;
	surface_H["Top"] = TopFace_H;
	surface_H["Bottom"] = BottomFace_H;
	Json::Value jonsFormal;
	jonsFormal["Formula"] = Formula;

	root.append(surface);
	root.append(surface_H);
	root.append(jonsFormal);

	


	return root;
}
