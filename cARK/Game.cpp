#include"Game.h"
Game::Game() {
	window.create(sf::VideoMode(WindowWidth, WindowHeight), L"ChronoArk");
}

Game::~Game() {

}

void Game::Initial(int w,int h) {

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

	isTriggered = false;
	cardTriggered = NULL;


	tBackGround.loadFromFile("source//texture//bg.png");
	uiVector.push_back(new UI(tBackGround, WindowWidth, WindowHeight, 0, 0));

	//参数调整
	tHeinFace.loadFromFile("source//texture//Hein_face .png");
	Hein = new Character(CharacterType::Hein, tHeinFace, WindowWidth / 6, WindowHeight / 6 , WindowWidth / 6, WindowHeight / 6*5,30,5);
	tPriestFace.loadFromFile("source//texture//Trisha_face .png");
	Priest = new Character(CharacterType::Priest, tPriestFace, WindowWidth / 6 , WindowHeight / 6 , WindowWidth / 6*2, WindowHeight / 6*5,30,0);
	characterVector.push_back(Hein);
	characterVector.push_back(Priest);

	//卡片加载,先加载到牌堆cardPile，然后回合初抽到持有卡牌helCards中	//之后有固定抽牌时间

	tCardAbility.loadFromFile("source//texture//ability.png");
	tCardData.loadFromFile("source//texture//CutScene_remembered_leryn_3.png");
	for (int i = 0; i < 5; i++) {
		cardVector.push_back(new AttackCard(tCardAbility, tCardData,Hein,1,1 ));
	}

	for (int i = 0; i < 5; i++) {

		cardVector.drawCard();
	}

	cardVector.setHeldCardsPosition();

	tMonsterArmor.loadFromFile("source//texture//W_Armor.png");
	monsterVector.push_back(new Monster(tMonsterArmor, WindowWidth / 4, WindowWidth / 3, WindowWidth / 5*2, WindowHeight / 6));



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
	characterVector.draw(window);
	monsterVector.draw(window);
	cardVector.setHeldCardsPosition();
	cardVector.draw(window);
	


	window.display();//把显示缓冲区的内容，显示在屏幕上

}

void Game::Input() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();//窗口如果要关闭，需要自己去调用close()函数
			gameQuit = true;
		}
		if (event.type == sf::Event::EventType::KeyReleased &&
			event.key.code == sf::Keyboard::Escape)
		{
			window.close();
			gameQuit = true;
		}
		if (event.type == sf::Event::MouseMoved) {
			Card* temp = cardVector.cardMouse(event.mouseMove.x, event.mouseMove.y);	//鼠标滑过卡片，显示卡牌信息
			if( cardMouseOver!=NULL)
				cardMouseOver->setMouseOverFalse();
			if(temp != NULL)
				temp->setMouseOverTrue();
			cardMouseOver = temp;
		}
		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left){
			if (isPlayerTurn) {
				if (Card*temp=cardVector.cardMouse(event.mouseButton.x, event.mouseButton.y)) {			//鼠标点击卡片
					if (temp != NULL && temp->getCardType() == CardType::draw &&!isTriggered ) {
						DrawCard* d = dynamic_cast <DrawCard*>(temp);
						d->drawCard(cardVector);
					}
					else if (isTriggered&& cardTriggered!=temp) {
						cardTriggered->setTriggeredFalse();
						cardTriggered = temp;
						temp->setTriggeredTrue();
					}
					else if(!isTriggered) {
						isTriggered = true;
						cardTriggered = temp;
						temp->setTriggeredTrue();
					}
					//cardVector.setHeldCardsPosition();
				}

				if (isTriggered ) {			//选中攻击卡片后点击怪物
					Role*temp=NULL;
					if(cardTriggered->getCardType() == CardType::attack)
						 temp = monsterVector.monsterMouse(event.mouseButton.x, event.mouseButton.y);
					else if(cardTriggered->getCardType() == CardType::cure)
						temp = characterVector.characterMouse(event.mouseButton.x, event.mouseButton.y);
					if (temp != NULL) {
						cardTriggered->action(temp);
						cardTriggered->setTriggeredFalse();
						cardVector.useCard(cardTriggered);
						isTriggered = false;
						cardTriggered = NULL;
					}
				}

				//if (isTriggered && cardTriggered->getCardType() == CardType::cure) {		//选中治疗卡片后点击玩家
				//	Character* temp = characterVector.characterMouse(event.mouseButton.x, event.mouseButton.y);
				//	if (temp != NULL) {
				//		cardTriggered->action(temp);
				//		cardTriggered->setTriggeredFalse();
				//		isTriggered = false;
				//		cardTriggered = NULL;
				//	}
				//}
			}
		}
		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Right) {
			if (isPlayerTurn&& isTriggered) {
				isTriggered = false;
				cardTriggered->setTriggeredFalse();
				cardTriggered = NULL;
				//cardVector.setHeldCardsPosition();
			}
		}
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

