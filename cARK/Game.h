#pragma once
#include "Base.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>

#include "Buff.h"
#include "Card.h"
#include "Character.h"
#include "Monster.h"
#include "Role.h"

using namespace sf;
class Game {
public:
	Game();
	~Game();
	void Run();
private:
	vector<Character*> characterVector;
	vector<Card*> cardVector;
	vector<Monster*> monsterVector;
	void Initial();
	void Input();
	void Logic();
	void Draw();
};