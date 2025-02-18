#pragma once
#include <KamataEngine.h>

namespace KamataEngine {

class GameScene {

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// サウンドデータハンドル
	uint32_t soundDataHandle_ = 0;

	// 音声再生ハンドル
	uint32_t voiceHandle_ = 0;

	// ImGuiで値を入力するための変数
	float inputFloat3[3] = {0, 0, 0};


public:

	// 初期化関数
	void Initialize();

	// スプライト
	Sprite* sprite_ = nullptr;

	// DirectX
	DirectXCommon* dxCommon = nullptr;

	// サウンド
	Audio* audio_ = nullptr;

	// モデル
	Model* model_ = nullptr;

	// キー入力
	Input* input_ = nullptr;

	// Imgui
	ImGuiManager* imguiManager_ = nullptr;

	// スクリーン
	WinApp* win_ = nullptr;

	// ワールドトランスフォーム
	WorldTransform worldTransform_;

	// ビュープロジェクション
	Camera viewProjection_;

	// デバッグカメラ
	DebugCamera* debagCamera_ = nullptr;

	// 更新関数
	void Update();

	// 描画関数
	void Draw();

	// コンストラクタの宣言と定義
	GameScene() {};

	// デストラクタの宣言
	~GameScene();
};

} // namespace KamataEngine