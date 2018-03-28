#include "Player.h"
#include "PlayerStandingState.h"
#include "GameDefine.h"

Player::Player()
{
	mAnimationStandingUp	=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 1, 1, 1, Define::FRAME_PER_SECOUND);
	mAnimationStandingDown	=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 5, 1, 5, Define::FRAME_PER_SECOUND);
	mAnimationStandingLeft	=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 3, 1, 3, Define::FRAME_PER_SECOUND);
	mAnimationStandingRight =	new Animation("Resource files/tank.png", 2, 16, 16, 1, 7, 1, 7, Define::FRAME_PER_SECOUND);
	mAnimationMovingUp		=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 1, 1, 2, Define::FRAME_PER_SECOUND);
	mAnimationMovingDown	=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 5, 1, 6, Define::FRAME_PER_SECOUND);
	mAnimationMovingLeft	=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 3, 1, 4, Define::FRAME_PER_SECOUND);
	mAnimationMovingRight	=	new Animation("Resource files/tank.png", 2, 16, 16, 1, 7, 1, 8, Define::FRAME_PER_SECOUND);

	this->mPlayerData = new PlayerData();
	this->mPlayerData->player = this;
	this->vx = 0;
	this->vy = 0;
	Dir = MoveDirection::Up;
	this->SetState(new PlayerStandingState(this->mPlayerData));
}

Player::~Player(){}

void Player::Update(float dt)
{
	mCurrentAnimation->Update(dt);

	if (this->mPlayerData->state)
	{
		this->mPlayerData->state->Update(dt);
	}

	Entity::Update(dt);
}
void Player::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mPlayerData->state)
	{
		this->mPlayerData->state->HandleKeyboard(keys);
	}
}
void Player::OnKeyPressed(int key)
{

}
void Player::OnKeyUp(int key)
{
}
void Player::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	mCurrentAnimation->SetPosition(this->GetPosition());

	mCurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
}
void Player::SetState(PlayerState *newState)
{
	delete this->mPlayerData->state;

	this->mPlayerData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
RECT Player::GetBound()
{
	RECT rect;
	rect.left = this->posX - mCurrentAnimation->GetWidth() / 2;
	rect.right = rect.left + mCurrentAnimation->GetWidth();
	rect.top = this->posY - mCurrentAnimation->GetHeight() / 2;
	rect.bottom = rect.top + mCurrentAnimation->GetHeight();

	return rect;
}
void Player::changeAnimation(PlayerState::StateName state)
{
	switch (state) 
	{
	case PlayerState::Standing:
		if (Dir == MoveDirection::Up)
			mCurrentAnimation = mAnimationStandingUp;
		else if (Dir == MoveDirection::Down)
			mCurrentAnimation = mAnimationStandingDown;
		else if (Dir == MoveDirection::Left)
			mCurrentAnimation = mAnimationStandingLeft;
		else
			mCurrentAnimation = mAnimationStandingRight;
		break;
	case PlayerState::MovingUp:
		mCurrentAnimation = mAnimationMovingUp;
		break;
	case PlayerState::MovingDown:
		mCurrentAnimation = mAnimationMovingDown;
		break;
	case PlayerState::MovingLeft:
		mCurrentAnimation = mAnimationMovingLeft;
		break;
	case PlayerState::MovingRight:
		mCurrentAnimation = mAnimationMovingRight;
		break;
	}
	this->width = mCurrentAnimation->GetWidth();
	this->height = mCurrentAnimation->GetHeight();
	mCurrentAnimation->SetCurrentTotalTime(Define::FRAME_PER_SECOUND);
}
MoveDirection Player::getMoveDirection()
{
	return Dir;
}
void Player::setMoveDirection(MoveDirection direction) {
	Dir = direction;
}
PlayerState::StateName Player::getState()
{
	return mCurrentState;
}