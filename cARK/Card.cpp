#include "Card.h"


Card::Card(Texture& texture, int width, int height,int x,int y) : Object(texture, width, height,x,y){}


AttackCard::AttackCard(Texture& texture, int width, int height,int x,int y) : Card(texture, width, height,x,y){}

CureCard::CureCard(Texture& texture, int width, int height,int x,int y) : Card(texture, width, height,x,y){}

FunctionCard::FunctionCard(Texture& texture, int width, int height,int x,int y) : Card(texture, width, height,x,y){}


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
	int h = Window_height / 6;
	for (auto it = heldCards.begin(); it != heldCards.end(); it++)
	{
		(*it)->setPosition(0, h);
		h += Window_height / 12;
	}
}

void CardVector::drawCard() {
	//之后要写清楚，卡牌为空的情况
	heldCards.push_back(*(cardPile.end()-1));
	cardPile.pop_back();
}