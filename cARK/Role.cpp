#include "Role.h"

Role::Role(Texture& texture, int width, int height, int x, int y, int tHP , int tatk , int tdefense ):Object(texture, width, height, x, y) {
	HP = tHP;
	currentHP = tHP;
	atk = tatk;
	currentAtk = tatk;
	defense = tdefense;
	currentDefense = tdefense;
}

Role::~Role(){
	for (auto it = bufferList.begin(); it !=bufferList.end(); it++)
	{
		delete((*it));
	}
}