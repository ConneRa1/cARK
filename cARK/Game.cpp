#include"Game.h"

Game::Game() {
	

	window.create(sf::VideoMode(Window_width, Window_height), L"ChronoArk");
}

Game::~Game() {

}

void Game::Run() {
	do
	{
		Initial();
		while (window.isOpen() && gameOver == false)
		{
			Input();
			Logic();
			Draw();
		}
	} while (window.isOpen() && !gameQuit);
}

void Game::Initial() {
	gameOver = false;
	gameQuit = false;

	tBackGround.loadFromFile("source//texture//Lab.png");
	backGround = new Object(tBackGround,Window_width, Window_height);
}

void Game::Draw() {
	window.clear();//清屏
	window.draw(backGround->getSprite());

	window.display();//把显示缓冲区的内容，显示在屏幕上
}

void Game::Input() {

}

void Game::Logic() {

}

//void Game::myDraw(Texture& texture, float x, float y, float width = 0, float height = 0) {
//	Sprite tempSprite;
//	tempSprite.setTexture(texture);
//	if(width!=0&&height!=0)
//		tempSprite.setTextureRect(IntRect(0, 0, width, height));
//	tempSprite.setPosition(x,y);
//	window.draw(tempSprite);
//}