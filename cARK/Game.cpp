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
	turn = 1;
	isPlayerTurn = true;


	tBackGround.loadFromFile("source//texture//bg.png");
	uiVector.push_back(new UI(tBackGround, Window_width, Window_height, 0, 0));

	//参数调整
	tHeinFace.loadFromFile("source//texture//Hein_face .png");
	Hein = new Character(CharacterType::Hein, tHeinFace, Window_width / 6, Window_height / 6 , Window_width / 6, Window_height / 6*5);
	tPriestFace.loadFromFile("source//texture//Trisha_face .png");
	Priest = new Character(CharacterType::Priest, tPriestFace, Window_width / 6 , Window_height / 6 , Window_width / 6*2, Window_height / 6*5);
	characterVector.push_back(Hein);
	characterVector.push_back(Priest);

	//卡片加载,先加载到牌堆cardPile，然后回合初抽到持有卡牌helCards中	//之后有固定抽牌时间

	tCardAbility.loadFromFile("source//texture//ability.png");
	for (int i = 0; i < 5; i++) {
		cardVector.push_back(CardFactory::getCard(attack, tCardAbility, Window_width / 6, Window_height / 12, 0, 0));
	}

	for (int i = 0; i < 5; i++) {
		cardVector.drawCard();
	}
	cardVector.setHeldCardsPosition();




	/*Hein=new()*/

	/*Texture tex;
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
	card.push_back(CardFactory::getCard(ct, tex, w, h, x, y));*/
}

void Game::Draw() {
	window.clear();//清屏
	
	/*backGround->draw(window);*/
	uiVector.draw(window);
	cardVector.draw(window);
	characterVector.draw(window);

	window.display();//把显示缓冲区的内容，显示在屏幕上

}

void Game::Input() {


	if (isPlayerTurn) {

	}
	else {

	}
}

void Game::Logic() {

	if (isPlayerTurn) {

	}

	else {

	}
}

//void Game::myDraw(Texture& texture, float x, float y, float width = 0, float height = 0) {
//	Sprite tempSprite;
//	tempSprite.setTexture(texture);
//	if(width!=0&&height!=0)
//		tempSprite.setTextureRect(IntRect(0, 0, width, height));
//	tempSprite.setPosition(x,y);
//	window.draw(tempSprite);
//}