#include "GameScene.h"
#include <KamataEngine.h>
using namespace KamataEngine;

// 初期化関数の定義
void GameScene::Initialize() 
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("Mario.jpg");

	// スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {100, 50});

}

void GameScene::Draw()
{
#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	///< summary>
	///
	/// </summary>

	sprite_->Draw();

	// 
	// スプライト描画後処理
	Sprite::PostDraw();
	#pragma endregion
}

// デストラクタの定義
GameScene::~GameScene()
{
	delete sprite_;
}
