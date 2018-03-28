#include "PlayerMovingUp.h"
#include "Player.h"
#include "GameDefine.h"
#include "PlayerStandingState.h"



PlayerMovingUp::PlayerMovingUp(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorY = 10.0f;
	this->mPlayerData->player->setMoveDirection(MoveDirection::Up);
}

PlayerMovingUp::~PlayerMovingUp()
{
}
void PlayerMovingUp::Update(float dt)
{
	
}
void PlayerMovingUp::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_UP])
	{
		this->mPlayerData->player->AddVy(acceleratorY);

		if (mPlayerData->player->GetVy() > Define::PLAYER_MAX_SPEED)
		{
			mPlayerData->player->SetVy(Define::PLAYER_MAX_SPEED);
		}
	}
	else {
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
	}
}
PlayerState::StateName PlayerMovingUp::GetState() {
	return PlayerState::MovingUp;
}