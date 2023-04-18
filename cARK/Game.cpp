#include"Game.h"
Game::Game() {
	window.create(sf::VideoMode(WindowWidth, WindowHeight), L"ChronoArk");
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

	isTriggered = false;
	cardTriggered = NULL;


	tBackGround.loadFromFile("source//texture//bg.png");
	uiVector.push_back(new UI(tBackGround, WindowWidth, WindowHeight, 0, 0));

	//��������
	tHeinFace.loadFromFile("source//texture//Hein_face .png");
	Hein = new Character(CharacterType::Hein, tHeinFace, WindowWidth / 6, WindowHeight / 6 , WindowWidth / 6, WindowHeight / 6*5,30,5);
	tPriestFace.loadFromFile("source//texture//Trisha_face .png");
	Priest = new Character(CharacterType::Priest, tPriestFace, WindowWidth / 6 , WindowHeight / 6 , WindowWidth / 6*2, WindowHeight / 6*5,30,0);
	characterVector.push_back(Hein);
	characterVector.push_back(Priest);

	tover.loadFromFile("source//texture//turnover.png");
	buttonVector.push_back(new Button(tover, WindowWidth / 12, WindowHeight / 24, 0, 85));
	buttonVector.push_back(new Button(tover, WindowWidth / 12, WindowHeight / 24, WindowWidth / 12, 85));
	tchange.loadFromFile("source//texture//exchange.png");
	buttonVector.push_back(new Button(tchange, WindowWidth / 12, WindowHeight / 24, WindowWidth / 6, 85));

	//��Ƭ����,�ȼ��ص��ƶ�cardPile��Ȼ��غϳ��鵽���п���helCards��	//֮���й̶�����ʱ��

	tCardAbility.loadFromFile("source//texture//ability.png");
	tCardData.loadFromFile("source//texture//CutScene_remembered_leryn_3.png");
	for (int i = 0; i < 10; i++) {
		cardVector.push_back(new AttackCard(tCardAbility, tCardData,Hein,1,1 ));
	}

	for (int i = 0; i < 5; i++) {

		cardVector.drawCard();
	}

	cardVector.setHeldCardsPosition();

	tMonsterArmor.loadFromFile("source//texture//W_Armor.png");
	monsterVector.push_back(new Monster(tMonsterArmor, WindowWidth / 4, WindowWidth / 3, WindowWidth / 5*2, WindowHeight / 6));



	/*Hein=new()*/
}

void Game::Draw() {
	window.clear();//����
	
	/*backGround->draw(window);*/
	uiVector.draw(window);
	characterVector.draw(window);
	monsterVector.draw(window);
	cardVector.setHeldCardsPosition();
	cardVector.draw(window);
	buttonVector.draw(window);


	window.display();//����ʾ�����������ݣ���ʾ����Ļ��

}

void Game::Input() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();//�������Ҫ�رգ���Ҫ�Լ�ȥ����close()����
			gameQuit = true;
		}
		if (event.type == sf::Event::EventType::KeyReleased &&
			event.key.code == sf::Keyboard::Escape)
		{
			window.close();
			gameQuit = true;
		}
		if (event.type == sf::Event::MouseMoved) {
			Card* temp = cardVector.cardMouse(event.mouseMove.x, event.mouseMove.y);	//��껬����Ƭ����ʾ������Ϣ
			if( cardMouseOver!=NULL)
				cardMouseOver->setMouseOverFalse();
			if(temp != NULL)
				temp->setMouseOverTrue();
			cardMouseOver = temp;
		}
		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left){
			if (isPlayerTurn) {
				//if (isTriggered && cardTriggered->getCardType() == CardType::cure) {		//ѡ�����ƿ�Ƭ�������
				//	Character* temp = characterVector.characterMouse(event.mouseButton.x, event.mouseButton.y);
				//	if (temp != NULL) {
				//		cardTriggered->action(temp);
				//		cardTriggered->setTriggeredFalse();
				//		isTriggered = false;
				//		cardTriggered = NULL;
				//	}
				//}
				if (ischanging)
				{
					if (Card* temp = cardVector.cardMouse(event.mouseButton.x, event.mouseButton.y))
					{
						cardVector.changeCard(temp);
						ischanging = false;
					}
					else ischanging = false;
				}
				else {
					if (Card* temp = cardVector.cardMouse(event.mouseButton.x, event.mouseButton.y)) {			//�������Ƭ
						if (temp != NULL && temp->getCardType() == CardType::draw && !isTriggered) {
							DrawCard* d = dynamic_cast <DrawCard*>(temp);
							d->drawCard(cardVector);
						}
						else if (isTriggered && cardTriggered != temp) {
							cardTriggered->setTriggeredFalse();
							cardTriggered = temp;
							temp->setTriggeredTrue();
						}
						else if (!isTriggered) {
							isTriggered = true;
							cardTriggered = temp;
							temp->setTriggeredTrue();
						}
						//cardVector.setHeldCardsPosition();
					}
					if (isTriggered) {			//ѡ�й�����Ƭ��������
						Role* temp = NULL;
						if (cardTriggered->getCardType() == CardType::attack)
							temp = monsterVector.monsterMouse(event.mouseButton.x, event.mouseButton.y);
						else if (cardTriggered->getCardType() == CardType::cure)
							temp = characterVector.characterMouse(event.mouseButton.x, event.mouseButton.y);
						if (temp != NULL) {
							cardTriggered->action(temp);
							cardTriggered->setTriggeredFalse();
							cardVector.useCard(cardTriggered);
							isTriggered = false;
							cardTriggered = NULL;
						}
					}
				}
				if (!isTriggered&&!ischanging)
				{
					if (Button* temp = buttonVector.ButtonMouse(event.mouseButton.x, event.mouseButton.y))
					{
						if (temp != NULL ) {
						cout << buttonVector.getID(temp) << endl;
						switch (buttonVector.getID(temp))
						{
						case 0:
							isPlayerTurn = false;
							break;
						case 1:
							//pass
							break;
						case 2:
							//����
							
							if (!ischanging)ischanging = true;
							cout << "���ƣ�"<<ischanging<< endl;
							break;
						default:
							break;
						}
					}
					}
					
				}
			}
			else {
				cout << "enemy turn over" << endl;
				isPlayerTurn = true;
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

