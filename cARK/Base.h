#pragma once

#include<string>
#include<vector>
#include<iostream> //便于调试
using std::vector;
using std::string;

#define MaxCardNum 10	//同时持有的最大卡牌数
#define WindowWidth 1280	//窗口宽度
#define WindowHeight 720	//窗口高度

//int _cardWidth=WindowWidth/6;
//int _cardHeight=WindowHeight/12;
//int _cardDataWidth=100;
//int _cardDataHeight=100;
//int _characterWidth=100;
//int _characterHeight=100;


typedef enum CharacterType {		//具体角色类型，比如lucy
	Lucy,
	Hein,
	Priest
};

typedef enum CardType {		//卡牌类型
	card,
	attack,
	cure,
	draw
};

typedef enum BuffType {		//具体buff类型

};

typedef enum UIType {		//UI种类
	button,
	ui
};
