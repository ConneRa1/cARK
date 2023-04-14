
#include "Object.h"

Object::Object(Texture&texture,int width,int height,int x,int y) {
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.scale((float)width / (float)texture.getSize().x,
		(float)height / (float)texture.getSize().y);
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	/*if (width != 0 && height != 0)
		sprite.setTextureRect(IntRect(0, 0, width, height));*/
}

void Object::setPosition(int x, int y) {	
	sprite.setPosition(x, y);
	this->x = x;
	this->y = y;
}

void Object::move(int x, int y) {	
	sprite.move(x, y);
	this->x += x;
	this->y += y;
}

//Sprite Object::getSprite() const{
//	return sprite;
//}

void Object::draw(RenderWindow& window) {

	window.draw(sprite);
}

bool Object::isIn(int x, int y) {
	if (x <= this->x + this->width && x >= this->x && y <= this->y + this->height && y >= this->y)
		return true;
	return false;
}