#pragma once
#include "Base.h"
#include "Object.h"
#include "Character.h"
#include "Monster.h"



class Card:public Object {
public:
	Card(Texture& texture,Texture&cardData, int width, int height,int x,int y);
	~Card();
	virtual CardType getCardType() const ;
	bool getTriggered() const;		//返回是否被选中
	void setTriggeredTrue();		//设置状态是
	void setTriggeredFalse();		//设置状态否
	bool getMouseOver() const;		//返回是否鼠标滑过
	void setMouseOverTrue();		
	void setMouseOverFalse();
	void draw(RenderWindow& window);
	Object* getCardData() const;
protected:
	int cost;
	//Character* character;
	//Role* target;

	bool isTriggered;
	bool isMouseOver;
	Object*cardData;			//卡片信息
};

class AttackCard:public Card{		//攻击类型卡片，指向敌方
public:

	AttackCard(Texture& texture, Texture& cardData, int width, int height,int x,int y);
	~AttackCard();
	CardType getCardType() const;
	
protected:
	
};

class CureCard:public Card{		//治疗类型卡片，指向角色
public:

	CureCard(Texture& texture,  Texture& cardData, int width, int height,int x,int y);
	~CureCard();
	CardType getCardType()const;

protected:

};

class FunctionCard:public Card {	//直接执行的卡片
public:
	FunctionCard(Texture& texture, Texture& cardData, int width, int height,int x,int y);
	~FunctionCard();
	CardType getCardType()const;
protected:

};



class CardFactory {		//卡片工厂
public:
	static Card* getCard(CardType num, Texture& texture, Texture& cardData, int width, int height, int x, int y)
	{
		switch (num)
		{
		case attack:
			return new  AttackCard(texture, cardData, width, height, x, y);
		case cure:
			return new CureCard(texture, cardData, width, height, x, y);
		case fun:
			return new FunctionCard(texture, cardData, width, height, x, y);
		default:
			break;
		}
	}
};

class CardVector {		//封装的card容器
public:
	CardVector() {};
	~CardVector() {};
	void draw(RenderWindow& window); //画出手中卡牌
	void push_back(Card* newCard);	//放回手中卡牌
	void setHeldCardsPosition();	//设置手中卡片的位置
	void drawCard();	//从牌堆中抽一张牌到持有卡牌中
	void useCard();		//使用卡片，弃牌到弃牌堆中
	Card* cardMouse(int x,int y);  //返回对应位置的卡片的指针
	//刷牌
	//把弃牌堆中的牌全部放回排队
private:
	vector<Card*> heldCards;	//持有的卡片
	vector<Card*> discardPile;	//弃牌堆中的卡片
	vector<Card*> cardPile;	//牌堆中的卡片
};