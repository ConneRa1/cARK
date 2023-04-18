#pragma once
#include"Role.h"

class MonsterFactory {		//怪物工厂

};

class Monster :public Role {
public:
	Monster(Texture& texture, int width, int height, int x, int y, int tHP = 0, int tatk = 0, int tdefense = 0);
	void draw(RenderWindow& window);
protected:

};

class MonsterVector {		//封装的monster容器
public:
	MonsterVector() {};
	~MonsterVector() {};
	void draw(RenderWindow& window);
	void push_back(Monster* newMonster);
	Monster* monsterMouse(int x, int y);  //返回对应位置的怪物的指针
private:
	vector<Monster*> monster;
};