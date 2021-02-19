/////////////////////////////////////
// Include
#include "tankPlayer.h"
#include "utils.h"


/////////////////////////////////////
// Class GameObject
TankPlayer::TankPlayer()
{
	m_type = GameObjectType_TankPlayer;

	m_health = kPlayerHealth;
	m_speed = kPlayerSpeed;

	m_destroyAfterDeath = false;
}

void TankPlayer::render()
{
	Rect texRect = kTankImage;
	texRect.x += kPixelsPerCell * m_direction * 2;
	setTextureRect(texRect);

	Tank::render();
}
