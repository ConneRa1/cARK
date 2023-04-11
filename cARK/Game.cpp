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

	tBackGround.loadFromFile("source//texture//bg.png");
	backGround = new Object(tBackGround,Window_width, Window_height);

	Texture tex;
	CardType ct;
	int w=50, h=30, x=10, y=10;
	tex.loadFromFile("source//texture//turnover.png");
	ct =attack;
	card.push_back(CardFactory::getCard(ct,tex,w,h,x,y));

	tex.loadFromFile("source//texture//exchange.png");
	x = 60; y = 10;
	card.push_back(CardFactory::getCard(ct,tex,w,h,x,y));

	tex.loadFromFile("source//texture//mp.png");
	x = 50; y = 50; w = 30;
	card.push_back(CardFactory::getCard(ct,tex,w,h,x,y));

	tex.loadFromFile("source//texture//ability_icon.png");
	x = 10; y = 50;
	card.push_back(CardFactory::getCard(ct,tex,w,h,x,y));

	tex.loadFromFile("source//texture//ability.png");
	x = 50; y = 80; w = 100; h = 50;
	card.push_back(CardFactory::getCard(ct,tex,w,h,x,y));

	tex.loadFromFile("source//texture//ability_icon.png");
	x = 10; y = 80; w = 30; h = 30;
	card.push_back(CardFactory::getCard(ct, tex, w, h, x, y));

	tex.loadFromFile("source//texture//ability.png");
	x = 50; y = 100; w = 100; h = 50;
	card.push_back(CardFactory::getCard(ct, tex, w, h, x, y));
	
}

void Game::Draw() {
	window.clear();//清屏
	window.draw(backGround->getSprite());


	for (auto it = card.begin(); it != card.end(); it++)
	{
		window.draw((*it)->getSprite());

	}


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