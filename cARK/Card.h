#pragma once
#include "Base.h"
#include "Object.h"
#include "Character.h"
#include "Monster.h"



class Card:public Object {
public:
	Card(Texture& texture, Texture& cardData, Character* character, int cost);
	~Card();
	virtual CardType getCardType() const ;
	bool getTriggered() const;		//�����Ƿ�ѡ��
	void setTriggeredTrue();		//����״̬��
	void setTriggeredFalse();		//����״̬��
	bool getMouseOver() const;		//�����Ƿ���껬��
	void setMouseOverTrue();		
	void setMouseOverFalse();
	void draw(RenderWindow& window);
	Object* getCardData() const;
	virtual void action(Role* target) {};
protected:
	int cost;
	Character* character;	//������˭
	bool isTriggered;
	bool isMouseOver;
	Object*cardData;			//��Ƭ��Ϣ
};

class CardVector {		//��װ��card����
public:
	CardVector() {};
	~CardVector() {};
	void draw(RenderWindow& window); //�������п���
	void push_back(Card* newCard);	//�Ż����п���
	void setHeldCardsPosition();	//�������п�Ƭ��λ��
	void drawCard();	//���ƶ��г�һ���Ƶ����п�����
	void useCard(Card* card);		//ʹ�ÿ�Ƭ�����Ƶ����ƶ���
	Card* cardMouse(int x, int y);  //���ض�Ӧλ�õĿ�Ƭ��ָ��
	//ˢ��
	//�����ƶ��е���ȫ���Ż��Ŷ�
private:
	vector<Card*> heldCards;	//���еĿ�Ƭ
	vector<Card*> discardPile;	//���ƶ��еĿ�Ƭ
	vector<Card*> cardPile;	//�ƶ��еĿ�Ƭ
};

class AttackCard:public Card{		//�������Ϳ�Ƭ��ָ��з�
public:
	AttackCard(Texture& texture, Texture& cardData, Character* character, int cost, int m = 1);
	~AttackCard() { Card::~Card(); };
	CardType getCardType() const;
	void action(Monster* target);
protected:
	int multiplyingPower;
};

class CureCard:public Card{		//�������Ϳ�Ƭ��ָ���ɫ
public:

	CureCard(Texture& texture, Texture& cardData, Character* character, int cost, int m = 1);
	~CureCard() { Card::~Card(); };
	CardType getCardType()const;
	void action(Character*target);
protected:
	int multiplyingPower;
};

class DrawCard:public Card {	//�鿨��Ƭ
public:
	DrawCard(Texture& texture, Texture& cardData, Character* character, int cost);
	~DrawCard() { Card::~Card(); };
	CardType getCardType()const;
	void drawCard(CardVector&cardVector);		//����
protected:

};



//class CardFactory {		//��Ƭ����
//public:
//	static Card* getCard(CardType num, Texture& texture, Texture& cardData, Character* character, int cost)
//	{
//		switch (num)
//		{
//		case attack:
//			return new  AttackCard(texture, cardData, character,  cost);
//		case cure:
//			return new CureCard(texture, cardData, character, cost);
//		case draw:
//			return new DrawCard(texture, cardData, character, cost);
//		default:
//			break;
//		}
//	}
//};

