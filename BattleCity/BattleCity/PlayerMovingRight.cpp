#include "PlayerMovingRight.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerStandingState.h"

PlayerMovingRight::PlayerMovingRight(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorX = 10.0f;
	this->mPlayerData->player->setMoveDirection(MoveDirection::Right);
}
void PlayerMovingRight::Update(float dt)
{

}
void PlayerMovingRight::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT])
	{
		this->mPlayerData->player->AddVx(acceleratorX);

		if (mPlayerData->player->GetVx() > Define::PLAYER_MAX_SPEED)
		{
			mPlayerData->player->SetVx(Define::PLAYER_MAX_SPEED);
		}
	}
	else {
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
	}
}

PlayerState::StateName PlayerMovingRight::GetState() {
	return PlayerState::MovingRight;
}

PlayerMovingRight::~PlayerMovingRight()
{
}
