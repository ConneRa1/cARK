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



class Game {
public:
	Game();
	~Game();
	void Run();
private:
	RenderWindow window;	//窗口
	vector<Character*> characterVector;	//角色容器，用于存储场上所有的角色
	vector<Monster*> monsterVector;	//怪物容器，用于存储场上所有的怪物
	vector<Card*> heldCards;	//持有的卡片
	vector<Card*> discardPile;	//弃牌堆中的卡片
	vector<Card*> cardPile;	//牌堆中的卡片

	bool gameOver, gameQuit;	//游戏运行阶段
	Texture tBackGround;	//纹理
	Object*backGround;	//背景
	//游戏基本逻辑
	void Initial();
	void Input();
	void Logic();
	void Draw();

	//自定的针对于SMFL的画图程序
	//void myDraw(Texture& texture, float x, float y, float width = 0,float height=0);
};