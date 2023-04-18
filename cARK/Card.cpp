#include "Card.h"

//card
Card::Card(Texture& texture, Texture& cardData, Character* character,int cost) : Object(texture, WindowWidth / 6, WindowHeight / 12,0,0){
	this->cardData = new Object(texture,100, 100, 0, 0);
	this->character = character;
	this->cost = cost;
	isMouseOver = false;
	isTriggered = false;
}

Card::~Card() {
	delete cardData;
}
CardType Card::getCardType() const{
	return CardType::card;
}
bool Card::getTriggered()const {
	return isTriggered;
}
void Card::setTriggeredTrue() {
	isTriggered = true;
}		
void Card::setTriggeredFalse() {
	isTriggered = false;
}

bool Card::getMouseOver()const {
	return isMouseOver;
}
void Card::setMouseOverTrue() {
	isMouseOver = true;
}
void Card::setMouseOverFalse() {
	isMouseOver = false;
}
void Card::draw(RenderWindow& window) {
	Object::draw(window);
	if (isMouseOver)
		cardData->draw(window);
}
Object* Card::getCardData() const {
	return cardData;
}
//cardVector
void  CardVector::draw(RenderWindow& window) {
	for (auto it = heldCards.begin(); it != heldCards.end(); it++) {
		(*it)->draw(window);
	}
}

void  CardVector::push_back(Card* newCard) {
	cardPile.push_back(newCard);

}

//位置参数要调整！！！
void CardVector::setHeldCardsPosition() {
	int h = WindowHeight / 6;
	for (auto it = heldCards.begin(); it != heldCards.end(); it++)
	{
		if ((*it)->getTriggered()) {
			(*it)->setPosition(WindowWidth / 12, h);
		}
		else {
			(*it)->setPosition(0, h);
		}
		if ((*it)->getMouseOver()) {
			if ((*it)->getTriggered()) {
				(*it)->getCardData()->setPosition(WindowWidth / 12 + WindowWidth / 6, h);
			}
			else {
				(*it)->getCardData()->setPosition(WindowWidth / 6, h);
			}
		}

		h += WindowHeight / 12;
	}
}

void CardVector::drawCard() {
	//之后要写清楚，卡牌为空的情况
	heldCards.push_back(*(cardPile.end() - 1));
	cardPile.pop_back();
}

Card* CardVector::cardMouse(int x, int y) {
	for (auto it = heldCards.begin(); it != heldCards.end(); it++) {
		if ((*it)->isIn(x, y)) {
			return *it;
		}
	}
	return NULL;
}


void CardVector::useCard(Card* card) {
	for (auto it = heldCards.begin(); it != heldCards.end(); it++) {
		if ((*it) == card) {
			heldCards.erase(it);
			discardPile.push_back(card);
			return;
		}
	}
	return;
}
//cardType
AttackCard::AttackCard(Texture& texture, Texture& cardData, Character* character, int cost,int m) : Card(texture, cardData,  character,  cost){
	multiplyingPower = m;
}

CureCard::CureCard(Texture& texture, Texture& cardData, Character* character, int cost,int m) : Card(texture, cardData, character, cost) {
	multiplyingPower = m;
}

DrawCard::DrawCard(Texture& texture, Texture& cardData, Character* character, int cost) : Card(texture, cardData, character, cost) {}

CardType AttackCard::getCardType() const{
	return CardType::attack;
}

void AttackCard::action(Monster* target) {
	int damage = character->getAtk() * multiplyingPower;
	target->changeHP(-damage);
}

CardType CureCard::getCardType() const {
	return CardType::cure;
}

void CureCard::action(Character* target) {
	int cure = character->getAtk() * multiplyingPower;
	target->changeHP(cure);
}
CardType DrawCard::getCardType() const {
	return CardType::draw;
}


void DrawCard :: drawCard(CardVector&cardVector) {//抽牌  //事例，抽两张牌
	for(int i=0;i<2;i++)
		cardVector.drawCard();
}



