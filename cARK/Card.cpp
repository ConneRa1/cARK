#include "Card.h"



Card::Card(Texture& texture, int width, int height,int x,int y) : Object(texture, width, height)
{
	setPosition(x, y);
}


AttackCard::AttackCard(Texture& texture, int width, int height,int x,int y) : Card(texture, width, height,x,y)
{
	
}

CureCard::CureCard(Texture& texture, int width, int height,int x,int y) : Card(texture, width, height,x,y)
{
	
}

FunctionCard::FunctionCard(Texture& texture, int width, int height,int x,int y) : Card(texture, width, height,x,y)
{
	
}
