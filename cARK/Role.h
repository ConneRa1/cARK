#pragma once
#include "Object.h"
#include "Base.h"
#include "Buff.h"

class Role:public Object {		//∂‘œÛ
public:
	Role(Texture& texture, int width, int height, int x, int y,int tHP=0,int tatk=0,int tdefense=0);
	~Role();
	int getMaxHP() const;
	int getHP() const;
	void setHP(int h);
	void changeHP(int h);
	int getAtk()const;
	int getDefence() const;

protected:

	int HP;
	int atk;
	int defense;

	int currentHP;
	int currentAtk;
	int currentDefense;
	vector<Buff*> bufferList;
};






