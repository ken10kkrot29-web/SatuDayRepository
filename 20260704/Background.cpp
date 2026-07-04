#include "Background.h"
#include "DxLib.h"

//=======================================================
// 初期化	
//=======================================================
void Background::Init()
{
	imageHandle = LoadGraph("Background(1).png");
}

//=======================================================
// 描画
//=======================================================
void Background::Draw(float cameraX)
{
	// 背景の描画
	DrawGraph(-(int)(cameraX * 0.5f),0,imageHandle,TRUE);
}
