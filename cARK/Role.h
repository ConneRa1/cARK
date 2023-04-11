#pragma once
#include "base.h"
#include "Buff.h"

class RoleFactory {

};

class Role {
public:
	virtual string GetType();
	
protected:
	int HP;
	int atk;
	int defense;
	int currentHP;
	int currentAtk;
	int currentDefense;
	vector<Buff*> bufferList;
};






