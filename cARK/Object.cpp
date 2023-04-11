
#include "Object.h"

Object::Object(Texture& texture,int width,int height) {	
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.scale((float)width / (float)texture.getSize().x,
		(float)height / (float)texture.getSize().y);
	/*if (width != 0 && height != 0)
		sprite.setTextureRect(IntRect(0, 0, width, height));*/
}

void Object::setPosition(int x, int y) {	//设定位置
	sprite.setPosition(x, y);
}

void Object::move(int x, int y) {	//设定位置
	sprite.move(x, y);
}

Sprite Object::getSprite() const{
	return sprite;
}