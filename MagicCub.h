#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <json/json.h>

const int CornerBlockNum = 8;
const int PrismaticBlockNum = 12;
const int CenterBlockNum = 6;

class MagicCub
{
private:
	std::string Formula;//打乱公式

	std::string FrontFace;
	std::string BackFace;
	std::string LeftFace;
	std::string RightFace;
	std::string TopFace;
	std::string BottomFace;

	std::string FrontFace_H;
	std::string BackFace_H;
	std::string LeftFace_H;
	std::string RightFace_H;
	std::string TopFace_H;
	std::string BottomFace_H;

	class CornerBlock
	{
	public:
		char* a, * b, * c;
		CornerBlock(char* p1 = NULL, char* p2 = NULL, char* p3 = NULL) :a(p1), b(p2), c(p3)
		{

		}


	};

	class PrismaticBlock
	{

	public:

		char* a, * b;

		PrismaticBlock(char* p1 = NULL, char* p2 = NULL) :a(p1), b(p2)
		{

		}


	};

	class CenterBlock
	{
	public:
		char* a;
		int matchidx;

		CenterBlock(char* p1 = NULL) :a(p1)
		{
			matchidx = 0;
		}

	};

	bool isHide;//判断魔方是否隐藏
	bool isDisrupt;//判断模仿是否处于打乱状态

	bool isMatchCenter;
	bool isCor;
	bool isPri;


	const int CornerColorNum = 9;
	const int PrismaticColorNum = 7;
	const int  CenterColorNum = 4;




	CornerBlock CorBlock[CornerBlockNum];
	PrismaticBlock PriBlock[PrismaticBlockNum];
	CenterBlock CntBlock[CenterBlockNum];


public:
	MagicCub();
	MagicCub(std::string formula);



	std::string getformula();

	void Uop();
	void uop();

	void Dop();
	void dop();

	void Lop();
	void lop();

	void Rop();
	void rop();

	void Fop();
	void fop();

	void Bop();
	void bop();

	void Rotate(std::string& Face);

	void Disrupt(const std::string formula);

	void UpdataHide();

	void reset();


	void print();

	void InitBlock();

	void HideCenter();

	void HideCor();

	void HidePri();

	void Hide();

	Json::Value ToJson();

	static std::string generateCubeScramble();



};

