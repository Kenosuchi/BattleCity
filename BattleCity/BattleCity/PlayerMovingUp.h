#pragma once
#include "PlayerState.h"

class PlayerMovingUp : public PlayerState
{
public:
	PlayerMovingUp(PlayerData *playerData);
	~PlayerMovingUp();

	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorY;
};

