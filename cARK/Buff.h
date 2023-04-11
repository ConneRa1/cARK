#pragma once
#include "Base.h"

class BuffFactory {		//buff����
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


class AttackBuff:public Buff {		//����ʱ�����buff
	AttackBuff();
	~AttackBuff();
};


class HittedBuff:public Buff {		//�ܻ�ʱ�����buff
	HittedBuff();
	~HittedBuff();
};

class EndBuff:public Buff {		//�غϽ���ʱ�����buff
	EndBuff();
	~EndBuff();
};


