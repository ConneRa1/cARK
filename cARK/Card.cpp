#include "Card.h"


Card::Card(Texture& texture, Texture& cardData, int width, int height,int x,int y) : Object(texture, width, height,x,y){
	this->cardData = new Object(texture, 100, 100, 0, 0);
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

AttackCard::AttackCard(Texture& texture, Texture& cardData, int width, int height,int x,int y) : Card(texture, cardData, width, height,x,y){}

CureCard::CureCard(Texture& texture, Texture& cardData, int width, int height,int x,int y) : Card(texture, cardData, width, height,x,y){}

FunctionCard::FunctionCard(Texture& texture, Texture& cardData, int width, int height,int x,int y) : Card(texture, cardData, width, height,x,y){}
CardType AttackCard::getCardType() const{
	return CardType::attack;
}
CardType CureCard::getCardType() const {
	return CardType::cure;
}

CardType FunctionCard::getCardType() const {
	return CardType::fun;
}

void  CardVector::draw(RenderWindow& window) {
	for (auto it = heldCards.begin(); it != heldCards.end(); it++){
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
			(*it)->setPosition(WindowWidth / 12,h);
		}
		else{
			(*it)->setPosition(0, h);
		}
		if ((*it)->getMouseOver())
			(*it)->getCardData()->setPosition(WindowWidth / 6, h);
		h += WindowHeight / 12;
	}
}

void CardVector::drawCard() {
	//之后要写清楚，卡牌为空的情况
	heldCards.push_back(*(cardPile.end()-1));
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



