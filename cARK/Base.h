#pragma once

#include<string>
#include<vector>
#include<iostream> //���ڵ���
using std::vector;
using std::string;

#define MaxCardNum 10	//ͬʱ���е��������
#define WindowWidth 1280	//���ڿ��
#define WindowHeight 720	//���ڸ߶�

//int _cardWidth=WindowWidth/6;
//int _cardHeight=WindowHeight/12;
//int _cardDataWidth=100;
//int _cardDataHeight=100;
//int _characterWidth=100;
//int _characterHeight=100;


typedef enum CharacterType {		//�����ɫ���ͣ�����lucy
	Lucy,
	Hein,
	Priest
};

typedef enum CardType {		//��������
	card,
	attack,
	cure,
	draw
};

typedef enum BuffType {		//����buff����

};

typedef enum UIType {		//UI����
	button,
	ui
};
