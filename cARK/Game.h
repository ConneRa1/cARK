#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>

using namespace sf;

class Game {
public:
	Game();
	~Game();

	void Run();
private:

	void Initial(int w, int h);

	void Input();

	void Logic();

	void Draw();
};