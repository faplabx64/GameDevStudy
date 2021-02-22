#pragma once
/////////////////////////////////////
// Include
#include "BuffTank.h"


/////////////////////////////////////
// Class BuffTank
BuffTank::BuffTank()
{
	m_type = GameObjectType_BuffTank;


}



void BuffTank::render()
{
	Rect texRect = kBuffTank;
	setTextureRect(texRect);

	GameObject::render();
}

void BuffTank::update(float dt)
{
	GameObject::update(dt);


}