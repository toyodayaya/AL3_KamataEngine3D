#pragma once
#include <KamataEngine.h>

namespace KamataEngine {

class GameScene {

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

public:

	// 初期化関数
	void Initialize();

	// スプライト
	Sprite* sprite_ = nullptr;

	DirectXCommon* dxCommon = nullptr;

	// 描画関数
	void Draw();

	// コンストラクタの宣言と定義
	GameScene() {};

	// デストラクタの宣言
	~GameScene();
};

} // namespace KamataEngine