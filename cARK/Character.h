#pragma once
#include"Role.h"
//class CharacterFactory {		//角色工厂
//
//};

class Character:public Role{
public:
	Character(CharacterType tname, Texture& texture, int width, int height, int x, int y, int tHP = 0, int tatk = 0, int tdefense = 0);
	~Character();
	
	
protected:
	CharacterType name;
	int old_HP;
	int actionNum;
};

class CharacterVector {		//封装的character容器
public:
	CharacterVector() {};
	~CharacterVector() {};
	void draw(RenderWindow& window);
	void push_back(Character* newCharacter);
	Character* characterMouse(int x, int y);  //返回对应位置的怪物的指针
private:
	vector<Character*> character;
};