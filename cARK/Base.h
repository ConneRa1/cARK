#pragma once

#include<string>
#include<vector>
#include<iostream> //���ڵ���

using namespace std;

#define MaxCardNum 10	//ͬʱ���е��������
#define Window_width 1280	//���ڿ��
#define Window_height 720	//���ڸ߶�



typedef enum CharacterType {		//�����ɫ���ͣ�����lucy
	Lucy,
	Hein,
	Priest
};

typedef enum CardType {		//���忨������
	
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
