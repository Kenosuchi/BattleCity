#include "PlayerStandingState.h"
#include "Player.h"
#include "PlayerMovingLeft.h"
#include "PlayerMovingDown.h"
#include "PlayerMovingRight.h"
#include "PlayerMovingUp.h"

PlayerStandingState::PlayerStandingState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVx(0);
	this->mPlayerData->player->SetVy(0);
}

PlayerStandingState::~PlayerStandingState(){}

void PlayerStandingState::Update(float dt) 
{

}

void PlayerStandingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_LEFT])
		this->mPlayerData->player->SetState(new PlayerMovingLeft(this->mPlayerData));
	else if(keys[VK_RIGHT])
		this->mPlayerData->player->SetState(new PlayerMovingRight(this->mPlayerData));
	else if(keys[VK_UP])
		this->mPlayerData->player->SetState(new PlayerMovingUp(this->mPlayerData));
	else if(keys[VK_DOWN])
		this->mPlayerData->player->SetState(new PlayerMovingDown(this->mPlayerData));
}
PlayerState::StateName PlayerStandingState::GetState()
{
	return PlayerState::Standing;
}