#pragma once
#include"Role.h"
class CharacterFactory {		//��ɫ����

};

class Character:public Role {
public:
	Character();
	~Character();
protected:
	int old_HP;
	int actionNum;
};

