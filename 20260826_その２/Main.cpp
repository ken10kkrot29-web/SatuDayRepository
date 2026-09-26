#pragma one 

#include "Collision.h"

class Player
{
private:
	float x, y;

	float velocityX;
	float velocityY;
	//ジャンプフラグ
	bool isJumping;
	//プレイヤーの当たり判定
	Collision collision;
	//足元の当たり判定
	Collision footCollision;
	//頭の当たり判定
	Collision headCollision;
public: Player();
	  Player(); 
	  //初期化 
	  //更新 
	  //描画
	  //マップとの衝突処理

};