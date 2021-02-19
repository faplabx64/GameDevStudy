#pragma once
/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class PowerUp
class PowerUpSpawner
	: public GameObject
{
public:
	PowerUpSpawner();

	virtual void update(float dt);

protected :
	int m_spawnTimer;

};