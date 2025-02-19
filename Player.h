#pragma once
#include <KamataEngine.h>

namespace KamataEngine {

/// <summary>
/// 自キャラ
/// </summary>

class Player 
{
private:
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

public:
	// 初期化関数
	void Initialize(Model *model,uint32_t textureHandle);
	// 更新関数
	void Update();
	// 描画関数
	void Draw(Camera &viewProjection);

	// コンストラクタの宣言と定義
	Player() {};
	// デストラクタの宣言
	~Player() {};
};
} // namespace KamataEngine