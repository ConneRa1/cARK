#include"Monster.h"

void  MonsterVector::draw(RenderWindow& window) {
	for (auto it = monster.begin(); it != monster.end(); it++)
	{
		(*it)->draw(window);
	}
}

void  MonsterVector::push_back(Monster* newMonster) {
	monster.push_back(newMonster);
}