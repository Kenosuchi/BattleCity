#pragma once
#include "PlayerState.h"

class PlayerMovingLeft : public PlayerState
{
public:
	PlayerMovingLeft(PlayerData *playerData);
	~PlayerMovingLeft();
	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorX;
};

