#pragma once

#include<string>
#include<vector>
#include<iostream> //���ڵ���
using std::vector;
using std::string;

#define MaxCardNum 10	//ͬʱ���е��������
#define WindowWidth 1280	//���ڿ��
#define WindowHeight 720	//���ڸ߶�

//int cardWidth;
//int cardHeight;
//int cardDataWidth;
//int cardDataHeight;


typedef enum CharacterType {		//�����ɫ���ͣ�����lucy
	Lucy,
	Hein,
	Priest
};

typedef enum CardType {		//���忨������
	card,
	attack,
	cure,
	fun
};

typedef enum BuffType {		//����buff����

};

typedef enum UIType {		//UI����
	button,
	ui
};
