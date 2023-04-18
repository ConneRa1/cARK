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
	bool getTriggered() const;		//�����Ƿ�ѡ��
	void setTriggeredTrue();		//����״̬��
	void setTriggeredFalse();		//����״̬��
	bool getMouseOver() const;		//�����Ƿ���껬��
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
	Object*cardData;			//��Ƭ��Ϣ
};

class AttackCard:public Card{		//�������Ϳ�Ƭ��ָ��з�
public:

	AttackCard(Texture& texture, Texture& cardData, int width, int height,int x,int y);
	~AttackCard();
	CardType getCardType() const;
	
protected:
	
};

class CureCard:public Card{		//�������Ϳ�Ƭ��ָ���ɫ
public:

	CureCard(Texture& texture,  Texture& cardData, int width, int height,int x,int y);
	~CureCard();
	CardType getCardType()const;

protected:

};

class FunctionCard:public Card {	//ֱ��ִ�еĿ�Ƭ
public:
	FunctionCard(Texture& texture, Texture& cardData, int width, int height,int x,int y);
	~FunctionCard();
	CardType getCardType()const;
protected:

};



class CardFactory {		//��Ƭ����
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

class CardVector {		//��װ��card����
public:
	CardVector() {};
	~CardVector() {};
	void draw(RenderWindow& window); //�������п���
	void push_back(Card* newCard);	//�Ż����п���
	void setHeldCardsPosition();	//�������п�Ƭ��λ��
	void drawCard();	//���ƶ��г�һ���Ƶ����п�����
	void useCard();		//ʹ�ÿ�Ƭ�����Ƶ����ƶ���
	Card* cardMouse(int x,int y);  //���ض�Ӧλ�õĿ�Ƭ��ָ��
	//ˢ��
	//�����ƶ��е���ȫ���Ż��Ŷ�
private:
	vector<Card*> heldCards;	//���еĿ�Ƭ
	vector<Card*> discardPile;	//���ƶ��еĿ�Ƭ
	vector<Card*> cardPile;	//�ƶ��еĿ�Ƭ
};