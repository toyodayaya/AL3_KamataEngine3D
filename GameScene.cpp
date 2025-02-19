#include "GameScene.h"
#include <KamataEngine.h>
using namespace KamataEngine;

// 初期化関数の定義
void GameScene::Initialize() 
{
	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("Mario.jpg");

	// dxCommonの初期化
	dxCommon = DirectXCommon::GetInstance();

	// 3Dモデルの生成
	model_ = Model::Create();

	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// プレイヤーの生成
	player_ = new Player();

	// プレイヤーの初期化
	player_->Initialize(model_, textureHandle_);

}

void GameScene::Update()
{
	// プレイヤーの更新
	player_->Update();
}

void GameScene::Draw()
{
#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	///< summary>
	///
	/// </summary>

	// プレイヤーの描画
	player_->Draw(viewProjection_);

	//// モデル描画
	//model_->Draw(worldTransform_, viewProjection_,textureHandle_);

	
	// スプライト描画後処理
	Model::PostDraw();

	#pragma endregion
}

// デストラクタの定義
GameScene::~GameScene()
{
	delete player_;
	delete model_;
}
