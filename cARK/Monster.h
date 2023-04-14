#pragma once
#include"Role.h"

class MonsterFactory {		//怪物工厂

};

class Monster :public Role {
public:

protected:

};

class MonsterVector {		//封装的monster容器
public:
	MonsterVector() {};
	~MonsterVector() {};
	void draw(RenderWindow& window);
	void push_back(Monster* newMonster);
private:
	vector<Monster*> monster;
};