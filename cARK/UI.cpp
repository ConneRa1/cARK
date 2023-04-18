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