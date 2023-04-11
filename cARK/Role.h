#pragma once
#include "Object.h"
#include "Base.h"
#include "Buff.h"

class Role {		//∂‘œÛ
public:
	virtual string getType();
	
protected:
	int HP;
	int atk;
	int defense;
	int currentHP;
	int currentAtk;
	int currentDefense;
	vector<Buff*> bufferList;
};






