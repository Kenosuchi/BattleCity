#include "PlayerMovingDown.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerStandingState.h"

PlayerMovingDown::PlayerMovingDown(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorY = -10.0f;
	this->mPlayerData->player->setMoveDirection(MoveDirection::Down);
}
void PlayerMovingDown::Update(float dt) 
{
	
}
void PlayerMovingDown::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_DOWN])
	{
		this->mPlayerData->player->AddVy(acceleratorY);
		if (mPlayerData->player->GetVy() < -Define::PLAYER_MAX_SPEED)
		{
			mPlayerData->player->SetVy(-Define::PLAYER_MAX_SPEED);
		}
	}
	else
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
}
PlayerState::StateName PlayerMovingDown::GetState() {
	return PlayerState::MovingDown;
}
PlayerMovingDown::~PlayerMovingDown()
{
}
