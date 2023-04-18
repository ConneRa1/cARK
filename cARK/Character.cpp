#include "Character.h"


Character::Character(CharacterType tname, Texture& texture, int width, int height, int x, int y, int tHP , int tatk , int tdefense ):Role(texture,width,height,x,y,tHP,tatk,tdefense){
	name = tname;
	old_HP = tHP;
	actionNum = 0;
}

Character::~Character() {
	Role::~Role();
}

void CharacterVector::draw(RenderWindow& window) {
	for (auto it = character.begin(); it != character.end(); it++)
	{
		(*it)->draw(window);
	}
}

void CharacterVector::push_back(Character* newCharacter) {
	character.push_back(newCharacter);
}

Character* CharacterVector::characterMouse(int x, int y) {
	for (auto it = character.begin(); it != character.end(); it++) {
		if ((*it)->isIn(x, y)) {
			return *it;
		}
	}
	return NULL;
}