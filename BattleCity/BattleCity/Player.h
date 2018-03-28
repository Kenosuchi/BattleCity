#pragma once
#include "Animation.h"
#include "Camera.h"
#include "Entity.h"
#include "PlayerData.h"
#include "PlayerState.h"
enum MoveDirection
{
	Left, // qua trai
	Right,// qua phai
	Up,   // di len
	Down, // di xuong
};
class Player : public Entity
{
public:
	Player();
	~Player();

	void Update(float dt);

	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	void SetState(PlayerState *newState);

	MoveDirection getMoveDirection();
	void setMoveDirection(MoveDirection);
	RECT GetBound();

	PlayerState::StateName Player::getState();

	//xu ly input
	//gom 256 key tuong ung true = dang dc nhan, false = khong dc nhan
	void HandleKeyboard(std::map<int, bool> keys);

	void OnKeyPressed(int key);

	void OnKeyUp(int key);


protected:
	PlayerData *mPlayerData;

	Animation   *mCurrentAnimation,
				*mAnimationStandingUp,
				*mAnimationStandingDown,
				*mAnimationStandingLeft,
				*mAnimationStandingRight,
				*mAnimationMovingUp,
				*mAnimationMovingDown,
				*mAnimationMovingLeft,
				*mAnimationMovingRight;

	void changeAnimation(PlayerState::StateName state);
	MoveDirection Dir;
	PlayerState::StateName mCurrentState;
};


