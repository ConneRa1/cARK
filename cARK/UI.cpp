#include"UI.h"

UI::UI(Texture& texture, int width, int height, int x, int y):Object(texture, width, height,x,y) {

}

Button::Button(Texture& texture, int width, int height, int x, int y) : UI(texture, width, height, x, y) {
	
}


void UIvector::draw(RenderWindow& window){
	for (auto it = ui.begin(); it != ui.end(); it++)
	{
		(*it)->draw(window);
	}
}

void UIvector::push_back(UI* newUI) {
	ui.push_back(newUI);
}

UI* UIvector::uiMouse(int x, int y) {
	for (auto it = ui.begin(); it != ui.end(); it++) {
		if ((*it)->isIn(x, y)) {
			return *it;
		}
	}
	return NULL;
}

void Buttonvector::draw(RenderWindow& window) {
	for (auto it = buttons.begin(); it != buttons.end(); it++)
	{
		(*it)->draw(window);
	}
}

void Buttonvector::push_back(Button* newButton) {
	buttons.push_back(newButton);
}

Button* Buttonvector::ButtonMouse(int x, int y) {
	for (auto it = buttons.begin(); it != buttons.end(); it++){
		if ((*it)->isIn(x, y)) {
			return *it;
		}
	}
	return NULL;
}
int Buttonvector::getID(Button* btn) {
	int id = 0;
	for (auto it= buttons.begin(); it != buttons.end(); it++) {
		if (*it == btn) {
			return id;
		}
		else id++;
	}
}