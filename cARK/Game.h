#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>

using namespace sf;

class Game {
public:
	Game();
	~Game();
	//��Ϸ������ں���
	void Run();
private:
	//��Ϸ��ʼ��
	void Initial();
	//���뺯��
	void Input();
	//��Ϸ���߼��ж�
	void Logic();
	//��Ϸ����������
	void Draw();
};