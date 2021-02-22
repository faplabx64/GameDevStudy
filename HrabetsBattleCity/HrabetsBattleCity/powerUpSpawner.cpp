/////////////////////////////////////
// Include
#include "powerUpSpawner.h"
#include "utils.h"


/////////////////////////////////////
// Class PowerUpSpawner
PowerUpSpawner::PowerUpSpawner()
{
	m_type       = GameObjectType_PowerUpSpawner;

	m_physical    = false;
}

void PowerUpSpawner::update(float dt)
{
	GameObject::update(dt);

	int allBuffsOnLevel  = m_game->getObjectsCount(GameObjectType_BuffTank);
	int countDeadEnemies =  m_game->getDiedEnemiesCount();
	
	if(allBuffsOnLevel < 1 && countDeadEnemies == 4 )
			m_game -> createObject(GameObjectType_BuffTank, getX(), getY());

	


}