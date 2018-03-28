#pragma once
#include "PlayerState.h"
class PlayerMovingRight : public PlayerState
{
public:
	PlayerMovingRight(PlayerData *playerData);
	~PlayerMovingRight();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
protected:
	float acceleratorX;
};

