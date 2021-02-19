#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class BuffTank
class BuffTank
	: public GameObject
{
public:
	BuffTank();
	virtual void render();
	virtual void update(float dt);

}; 


