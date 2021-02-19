/////////////////////////////////////
// Include
#include "powerUpSpawner.h"
#include "utils.h"


/////////////////////////////////////
// Class PowerUpSpawner
PowerUpSpawner::PowerUpSpawner()
{
	m_type       = GameObjectType_PowerUpSpawner;

	m_spawnRandom = GetRandomInt(2, kBuffCount);

	m_physical   = false;
}

void PowerUpSpawner::update(float dt)
{
	GameObject::update(dt);

	int heartBuffsOnLevel = m_game->getObjectsCount(GameObjectType_BuffTank);
	//int lvlUpBuffsOnLevel =
	int allBuffsOnLevel = heartBuffsOnLevel + 0;
	int countDeadEnemies =  m_game->getDiedEnemiesCount();
	
	//Fix later
	/*if(m_spawnRandom == 2  && allBuffsOnLevel < 1 && countDeadEnemies == 4)
	m_game -> createObject(GameObjectType_BuffTank, getX(), getY());
	*/


}