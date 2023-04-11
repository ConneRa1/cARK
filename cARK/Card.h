#pragma once
#include "Base.h"
#include "Object.h"
#include "Character.h"
#include "Monster.h"

class CardFactory {		//��Ƭ����
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

class AttackCard{		//�������Ϳ�Ƭ��ָ��з�
public:

	AttackCard();
	~AttackCard();
	
protected:
	
};

class CureCard{		//�������Ϳ�Ƭ��ָ���ɫ
public:
	CureCard();
	~CureCard();

protected:

};

class FunctionCard {	//ֱ��ִ�еĿ�Ƭ
public:
	FunctionCard();
	~FunctionCard();
protected:

};
