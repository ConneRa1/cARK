#pragma once
#include "Base.h"

class BuffFactory {		//buff工厂
public:
	
};

class Buff{
public:
	Buff();
	~Buff();
	virtual string getType() {};
	virtual void effect() {};
protected:
	int duration;
};


class AttackBuff:public Buff {		//攻击时掉层的buff
	AttackBuff();
	~AttackBuff();
};


class HittedBuff:public Buff {		//受击时掉层的buff
	HittedBuff();
	~HittedBuff();
};

class EndBuff:public Buff {		//回合结束时掉层的buff
	EndBuff();
	~EndBuff();
};


