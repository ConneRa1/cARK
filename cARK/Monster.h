#pragma once
#include"Role.h"

class MonsterFactory {		//���﹤��

};

class Monster :public Role {
public:

protected:

};

class MonsterVector {		//��װ��monster����
public:
	MonsterVector() {};
	~MonsterVector() {};
	void draw(RenderWindow& window);
	void push_back(Monster* newMonster);
private:
	vector<Monster*> monster;
};