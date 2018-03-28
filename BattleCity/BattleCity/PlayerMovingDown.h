#pragma once
#include "PlayerState.h"
class PlayerMovingDown : public PlayerState
{
public:
	PlayerMovingDown(PlayerData *playerData);
	~PlayerMovingDown();
	void Update(float dt);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorY;
};

