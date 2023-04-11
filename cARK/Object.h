#pragma once
#include "Base.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Object {		//可显示物体的共有父类
public:
	Object(Texture& texture, int width = 0, int height = 0);
	void setPosition(int x, int y);//设定位置，不设置则默认为0;
	void move(int x, int y);  //移动
	Sprite getSprite() const;
protected:
	Sprite sprite;
};