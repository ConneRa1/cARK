#pragma once
#include "Base.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Object {		//����ʾ����Ĺ��и���
public:
	Object(Texture& texture, int width = 0, int height = 0);
	void setPosition(int x, int y);//�趨λ�ã���������Ĭ��Ϊ0;
	void move(int x, int y);  //�ƶ�
	Sprite getSprite() const;
protected:
	Sprite sprite;
};