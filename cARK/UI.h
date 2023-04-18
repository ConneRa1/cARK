
#include "Object.h"

class UI:public Object {
public:
	UI(Texture& texture,int width,int height, int x, int y);
protected:

};

class Button :public UI {
public:
	Button(Texture& texture, int width, int height, int x, int y);
	
protected:
	
};

class UIvector {		//封装的ui容器
public:
	UIvector() {};
	~UIvector() {};
	void draw(RenderWindow& window);
	void push_back(UI* newUI);
	UI* uiMouse(int x, int y);
private:
	vector<UI*> ui;
	
};


class Buttonvector {		//封装的ui容器
public:
	Buttonvector() {};
	~Buttonvector() {};
	void draw(RenderWindow& window);
	void push_back(Button* newUI);
	Button* ButtonMouse(int x, int y);
	int getID(Button* btn);
private:
	vector<Button*> buttons;

};

//
//case button:
//	return  new Card(texture, width, height, x, y);