#pragma once
#include"Role.h"
//class CharacterFactory {		//��ɫ����
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

class CharacterVector {		//��װ��character����
public:
	CharacterVector() {};
	~CharacterVector() {};
	void draw(RenderWindow& window);
	void push_back(Character* newCharacter);
private:
	vector<Character*> character;
};