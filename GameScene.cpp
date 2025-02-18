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

	// dxCommonの初期化
	dxCommon = DirectXCommon::GetInstance();

	// キー入力の初期化
	input_ = Input::GetInstance();

	// スクリーンの初期化
	win_ = WinApp::GetInstance();

	// Imguiの初期化
	imguiManager_ = ImGuiManager::GetInstance();
	imguiManager_->Initialize(win_, dxCommon);

	// 3Dモデルの生成
	model_ = Model::Create();

	// デバッグカメラの生成
	debagCamera_ = new DebugCamera(1280,720);

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// サウンド変数の初期化
	audio_ = Audio::GetInstance();

	// サウンドデータの読み込み
	soundDataHandle_ = audio_->LoadWave("fanfare.wav");

	
	// サウンドの再生
	voiceHandle_ = audio_->PlayWave(soundDataHandle_,true);

	// ライン描画が参照するビュープロジェクションを指定する
	PrimitiveDrawer::GetInstance()->SetViewProjection(&viewProjection_);

	// 軸方向表示の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);

	// 軸方向表示が参照するビュープロジェクションを指定する
	AxisIndicator::GetInstance()->SetTargetCamera(&debagCamera_->GetCamera());

}

void GameScene::Update()
{
	// スプライトの今の座標を取得
	Vector2 pos = sprite_->GetPosition();

	// 座標を{2,1}移動
	pos.x += 2.0f;
	pos.y += 1.0f;

	// 移動した座標をスプライトに反映
	sprite_->SetPosition(pos);

	// スペースキーを押した瞬間に再生
	if (input_->TriggerKey(DIK_SPACE))
	{
		// 音声停止
		audio_->StopWave(voiceHandle_);
	}

	// デバッグカメラの更新
	debagCamera_->Update();

	#ifdef _DEBUG

	// デバッグコードを表示
	imguiManager_->Begin();
	ImGui::Begin("Debug1");

	// float3入力ボックス
	ImGui::InputFloat3("InputFloat3", inputFloat3);

	// float3スライダー
	ImGui::SliderFloat3("SliderFloat3", inputFloat3, 0.0f,1.0f);

	// デモウィンドウの表示を有効化
	ImGui::ShowDemoWindow();

	ImGui::Text("Kamata Tarou %d.%d.%d", 2050, 12, 31);
	imguiManager_->End();

#endif // DEBUG

	
}

void GameScene::Draw()
{
#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	///< summary>
	///
	/// </summary>

	// スプライト描画
	//sprite_->Draw();

	// モデル描画
	//model_->Draw(worldTransform_, viewProjection_,textureHandle_);

	// デバッグカメラ描画
	model_->Draw(worldTransform_, debagCamera_->GetCamera(), textureHandle_);

	// スプライト描画後処理
	Model::PostDraw();

	// ライン描画
	PrimitiveDrawer::GetInstance()->DrawLine3d({0, 0, 0}, {0, 10, 0}, {1.0f, 0.0f, 0.0f, 1.0f});

	#pragma endregion
}

// デストラクタの定義
GameScene::~GameScene()
{
	delete sprite_;
	delete model_;
	delete debagCamera_;
}
