#include"Monster.h"


Monster::Monster(Texture& texture, int width, int height, int x, int y, int tHP , int tatk , int tdefense ) :Role(texture, width, height, x, y, tHP, tatk, tdefense){}

void Monster::draw(RenderWindow& window) {
	Object::draw(window);

}

void  MonsterVector::draw(RenderWindow& window) {
	for (auto it = monster.begin(); it != monster.end(); it++)
	{
		(*it)->draw(window);
	}
}

void  MonsterVector::push_back(Monster* newMonster) {
	monster.push_back(newMonster);
}

Monster* MonsterVector::monsterMouse(int x, int y) {
	for (auto it = monster.begin(); it != monster.end(); it++) {
		if ((*it)->isIn(x, y)) {
			return *it;
		}
	}
	return NULL;
}