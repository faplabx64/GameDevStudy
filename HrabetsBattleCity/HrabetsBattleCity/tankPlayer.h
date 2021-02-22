#pragma once


/////////////////////////////////////
// Include
#include "tank.h"


/////////////////////////////////////
// Class TankPlayer
class TankPlayer
	: public Tank
{
public:
	TankPlayer();

	void render();
	void update(float dt);

	void plusOneHeart();

protected:
	int m_heart;

};
