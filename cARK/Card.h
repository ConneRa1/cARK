#pragma once
#include "Base.h"
#include "Character.h"
#include "Monster.h"

class CardFactory {
public:

};
class Card {
public:
	Card();
	~Card();
	void Triggered();
protected:
	int cost;
	Character* character;
	Role* target;
	bool isTriggered;
	bool isMouseOver;
};

class AttackCard{
public:

	AttackCard();
	~AttackCard();

protected:

};

class CureCard{
public:
	CureCard();
	CureCard();

protected:

};

class FunctionCard {
public:
	FunctionCard();
	~FunctionCard();
protected:

};
