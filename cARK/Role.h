#pragma once
#include "Object.h"
#include "Base.h"
#include "Buff.h"

class Role:public Object {		//¶ÔÏó
public:
	Role(Texture& texture, int width, int height, int x, int y,int tHP=0,int tatk=0,int tdefense=0);
	~Role();
	virtual string getType() {
		return "";
	};
	
protected:

	int HP;
	int atk;
	int defense;
	int currentHP;
	int currentAtk;
	int currentDefense;
	vector<Buff*> bufferList;
};






