#pragma once
#include "Base.h"
#include "Object.h"
#include "Character.h"
#include "Monster.h"



class Card:public Object {
public:
	Card(Texture& texture, int width, int height,int x,int y);
	~Card();
	void triggered();
protected:
	int cost;
	Character* character;
	Role* target;
	bool isTriggered;
	bool isMouseOver;
	Texture tcard;	//纹理
	
};

class AttackCard:public Card{		//攻击类型卡片，指向敌方
public:

	AttackCard(Texture& texture, int width, int height,int x,int y);
	~AttackCard();
	
protected:
	
};

class CureCard:public Card{		//治疗类型卡片，指向角色
public:

	CureCard(Texture& texture, int width, int height,int x,int y);
	~CureCard();

protected:

};

class FunctionCard:public Card {	//直接执行的卡片
public:
	FunctionCard(Texture& texture, int width, int height,int x,int y);
	~FunctionCard();
protected:

};

class CardFactory {		//卡片工厂
public:
	static Card *getCard(CardType num,Texture& texture, int width, int height, int x, int y)
	{
		switch (num)
		{
		case button:
			return  new Card(texture,width,height,x,y);
		case attack:
			return new  AttackCard(texture, width, height, x, y);
		case cure:
			return new CureCard(texture, width, height, x, y);
		case fun:
			return new FunctionCard(texture, width, height, x, y);
		default:
			break;
		}

	}
};