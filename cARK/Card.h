#pragma once
#include "Base.h"
#include "Object.h"
#include "Character.h"
#include "Monster.h"

class CardFactory {		//卡片工厂
public:

};
class Card {
public:
	Card();
	~Card();
	void triggered();
protected:
	int cost;
	Character* character;
	Role* target;
	bool isTriggered;
	bool isMouseOver;

	
};

class AttackCard{		//攻击类型卡片，指向敌方
public:

	AttackCard();
	~AttackCard();
	
protected:
	
};

class CureCard{		//治疗类型卡片，指向角色
public:
	CureCard();
	~CureCard();

protected:

};

class FunctionCard {	//直接执行的卡片
public:
	FunctionCard();
	~FunctionCard();
protected:

};
