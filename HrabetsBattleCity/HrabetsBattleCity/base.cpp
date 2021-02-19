/////////////////////////////////////
// Include
#include "base.h"


/////////////////////////////////////
// Class GameObject
Base::Base()
{
	m_type = GameObjectType_Base;

	m_width = kBaseColumns;
	m_height = kBaseRows;

	m_health = kBaseHealth;
	m_destroyAfterDeath = false;
}

void Base::render()
{
	Rect texRect = kBaseImage;
	texRect.y += (3 - m_health) * m_height * kPixelsPerCell;
	setTextureRect(texRect);

	GameObject::render();
}
