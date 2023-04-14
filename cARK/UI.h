#include"Base.h"
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

class UIvector {		//·â×°µÄuiÈÝÆ÷
public:
	UIvector() {};
	~UIvector() {};
	void draw(RenderWindow& window);
	void push_back(UI* newUI);
private:
	vector<UI*> ui;
};

//
//case button:
//	return  new Card(texture, width, height, x, y);