#pragma once

#include<iostream>
#include<SFML/Audio.hpp>

#include "Base.h"
#include "Object.h"
#include "Buff.h"
#include "Card.h"
#include "Character.h"
#include "Monster.h"
#include "Role.h"
#include "UI.h"





class Game {
public:
	Game();
	~Game();
	void Run();
private:
	RenderWindow window;	//窗口
	

	vector<Monster*> monsterVector;	//怪物容器，用于存储场上所有的怪物
	
	CardVector cardVector;
	UIvector uiVector;	//ui容器
	CharacterVector characterVector;	//角色容器，用于存储场上所有的角色
	//display测试用
	vector<Card*> card;

	Character* Hein,*Priest;	//人物
	int turn;	//回合数
	bool isPlayerTurn;	//是否是人物的回合
	bool gameOver, gameQuit;	//游戏运行阶段
	Texture tBackGround,tHeinFace,tPriestFace,tCardAbility;	//纹理
	//Object*backGround;	//背景
	//游戏基本逻辑
	void Initial();
	void Input();
	void Logic();
	void Draw();

	//自定的针对于SMFL的画图程序
	//void myDraw(Texture& texture, float x, float y, float width = 0,float height=0);
};