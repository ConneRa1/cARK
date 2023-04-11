#pragma once
#include "Base.h"
#include "Role.h";

class BuffFactory {
public:
	
};

class Buff {
public:
	Buff();
	~Buff();
	virtual string GetType() {};
	virtual void Effect() {};
protected:
	int duration;
};


class AttackBuff:public Buff {
	AttackBuff();
	~AttackBuff();
};


class HittedBuff:public Buff {
	HittedBuff();
	~HittedBuff();
};

class EndBuff:public Buff {
	EndBuff();
	~EndBuff();
};


