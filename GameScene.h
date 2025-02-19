#pragma once
#include <KamataEngine.h>
#include "Player.h"

namespace KamataEngine {

class GameScene {

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;


public:

	// 初期化関数
	void Initialize();

	// DirectX
	DirectXCommon* dxCommon = nullptr;

	// モデル
	Model* model_ = nullptr;

	// ビュープロジェクション
	Camera viewProjection_;

	// プレイヤー
	Player* player_ = nullptr;

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