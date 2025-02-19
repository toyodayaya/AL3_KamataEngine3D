#include "Player.h"
#include <KamataEngine.h>

namespace KamataEngine {

// 初期化関数
void Player::Initialize(Model* model, uint32_t textureHandle)
{
	// NULLポインタチェック
	assert(model);
	model_ = model;
	textureHandle_ = textureHandle;

	// ワールド変換の初期化
	worldTransform_.Initialize();
}

// 更新関数
void Player::Update() 
{
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

// 描画関数
void Player::Draw(Camera& viewProjection) {
	// モデル描画
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

} // namespace KamataEngine