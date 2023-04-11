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
	Texture tcard;	//����
	
};

class AttackCard:public Card{		//�������Ϳ�Ƭ��ָ��з�
public:

	AttackCard(Texture& texture, int width, int height,int x,int y);
	~AttackCard();
	
protected:
	
};

class CureCard:public Card{		//�������Ϳ�Ƭ��ָ���ɫ
public:

	CureCard(Texture& texture, int width, int height,int x,int y);
	~CureCard();

protected:

};

class FunctionCard:public Card {	//ֱ��ִ�еĿ�Ƭ
public:
	FunctionCard(Texture& texture, int width, int height,int x,int y);
	~FunctionCard();
protected:

};

class CardFactory {		//��Ƭ����
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