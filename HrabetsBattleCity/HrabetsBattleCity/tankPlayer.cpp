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
	m_heart = kHeart;

	m_destroyAfterDeath = false;

}

void TankPlayer::plusOneHeart()
{
	m_heart += 1;
}
void TankPlayer::render()
{
	Rect texRect = kTankImage;
	texRect.x += kPixelsPerCell * m_direction * 2;
	setTextureRect(texRect);

	Tank::render();
}

void TankPlayer::update(float dt)
{
	Tank::update(dt);

	if (m_health <= 0 && m_heart > 0) {
		m_health += 1;
		m_heart -= 1;

		this->setX(37);
		this->setY(33);
	}
}
