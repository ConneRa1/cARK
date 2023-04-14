#pragma once

#include<string>
#include<vector>
#include<iostream> //便于调试

using namespace std;

#define MaxCardNum 10	//同时持有的最大卡牌数
#define Window_width 1280	//窗口宽度
#define Window_height 720	//窗口高度



typedef enum CharacterType {		//具体角色类型，比如lucy
	Lucy,
	Hein,
	Priest
};

typedef enum CardType {		//具体卡牌类型
	
	attack,
	cure,
	fun
};

typedef enum BuffType {		//具体buff类型

};

typedef enum UIType {		//UI种类
	button,
	ui
};
