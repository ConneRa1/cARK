#pragma once
#include"Role.h"

class MonsterFactory {		//���﹤��

};

class Monster :public Role {
public:
	Monster(Texture& texture, int width, int height, int x, int y, int tHP = 0, int tatk = 0, int tdefense = 0);
	void draw(RenderWindow& window);
protected:

};

class MonsterVector {		//��װ��monster����
public:
	MonsterVector() {};
	~MonsterVector() {};
	void draw(RenderWindow& window);
	void push_back(Monster* newMonster);
	Monster* monsterMouse(int x, int y);  //���ض�Ӧλ�õĹ����ָ��
private:
	vector<Monster*> monster;
};