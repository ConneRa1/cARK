#pragma once
#include "Base.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Object {		//����ʾ����Ĺ��и���
public:
	Object(Texture& texture, int width = 0, int height = 0,int x=0,int y=0);	//�������textureȫ�����أ�����width��height�Ǿ����С
	void setPosition(int x, int y);//�趨λ�ã���������Ĭ��Ϊ0;
	void move(int x, int y);  //�ƶ�
	//Sprite getSprite() const;	//����sprite��������ʾ

	void draw(RenderWindow&window);		//��window����ʾ�������
	bool isIn(int x, int y);	//�ж��Ƿ��ڷ�Χ��
protected:
	Sprite sprite;
	int x, y;
	int width, height;
};