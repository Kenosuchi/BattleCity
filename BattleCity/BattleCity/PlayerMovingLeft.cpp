#include "PlayerMovingLeft.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerStandingState.h"

PlayerMovingLeft::PlayerMovingLeft(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorX = -10.0f;
	this->mPlayerData->player->setMoveDirection(MoveDirection::Left);
}
void PlayerMovingLeft::Update(float dt) 
{
	
}
void PlayerMovingLeft::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_LEFT])
	{
		this->mPlayerData->player->AddVx(acceleratorX);

		if (mPlayerData->player->GetVx() < -Define::PLAYER_MAX_SPEED)
		{
			mPlayerData->player->SetVx(-Define::PLAYER_MAX_SPEED);
		}
	}
	else {
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
	}
}
PlayerState::StateName PlayerMovingLeft::GetState() {
	return PlayerState::MovingLeft;
}
PlayerMovingLeft::~PlayerMovingLeft()
{
}
