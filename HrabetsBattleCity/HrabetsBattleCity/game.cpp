/////////////////////////////////////
// Include
#include "game.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "level.h"
#include "wall.h"
#include "base.h"
#include "bullet.h"
#include "tankPlayer.h"
#include "tankEnemy.h"
#include "enemySpawner.h"
#include "powerUpSpawner.h"
#include "buffTank.h"
#include <ctime>
#include "Framework.h"


/////////////////////////////////////
// Global
Sprite* g_atlas00 = nullptr;
bool isHelmeActive = false;


/////////////////////////////////////
// Class MyFramework
MyFramework::MyFramework()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;

	for (int i = 0; i < kObjectsCountMax; i++)
		m_objects[i] = 0;

	m_base = 0;
	m_player1 = 0;

	m_diedEnemiesCount = 0;
}

MyFramework::~MyFramework()
{
	if (g_atlas00)
		delete g_atlas00;
}

void MyFramework::PreInit(int& width, int& height, bool& fullscreen)
{
	fullscreen = false;

	srand(time(0));
}

bool MyFramework::Init()
{
	Close();

	m_diedEnemiesCount = 0;

	// Load level
	for (int r = 0; r < kLevelRows; r++)
	{
		for (int c = 0; c < kLevelColumns; c++)
		{
			unsigned char cellSymbol = kLevelData0[r][c];

			switch (cellSymbol)
			{
			case CellSymbol_BrickWall:
			{
				Wall* wall = (Wall*)createObject(GameObjectType_Wall, c, r);
				wall->setTextureRect(kBrickWallImage);
				break;
			}

			case CellSymbol_SteelWall:
			{
				Wall* wall = (Wall*)createObject(GameObjectType_Wall, c, r);
				wall->setTextureRect(kSteelWallImage);
				wall->setInvulnerable(true);
				break;
			}

			case CellSymbol_Base:
			{
				m_base = createObject(GameObjectType_Base, c, r);
				m_base -> setTextureRect(kBaseImage);
				break;
			}

			case CellSymbol_Player1:
			{
				m_player1 = (TankPlayer*)createObject(GameObjectType_TankPlayer, c + 0.5, r + 0.5);

				break;
			}

			case CellSymbol_EnemySpawner:
			{
				createObject(GameObjectType_EnemySpawner, c, r);
				break;
			}

			case CellSymbol_PowerUpSpawner:
			{
				createObject(GameObjectType_PowerUpSpawner, c, r);
				break;
			}
			}
		}
	}

	return true;
}

void MyFramework::Close()
{
	for (int i = 0; i < kObjectsCountMax; i++)
		if (m_objects[i] != 0)
		{
			delete m_objects[i];
			m_objects[i] = 0;
		}
}

bool MyFramework::Tick()
{
	drawTestBackground();

	if (!g_atlas00)
	{
		g_atlas00 = createSprite("data/GeneralSprites.png");

		Init();
	}

	// Calculate delta time
	unsigned int clockNow = getTickCount();
	unsigned int deltaClock = clockNow - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC; // fix define
	m_clockLastFrame = clockNow;

	render();
	update(deltaTime);

	return !m_isGameActive;
}

void MyFramework::onMouseMove(int x, int y, int xrelative, int yrelative)
{
}

void MyFramework::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT)
		m_player1->fire();
}

void MyFramework::onKeyPressed(FRKey k)
{
	if (!m_player1)
		return;

	switch (k)
	{
	case FRKey::RIGHT:
		m_player1->move(Direction::Direction_Right);
		break;
	case FRKey::LEFT:
		m_player1->move(Direction::Direction_Left);
		break;
	case FRKey::DOWN:
		m_player1->move(Direction::Direction_Down);
		break;
	case FRKey::UP:
		m_player1->move(Direction::Direction_Up);
		break;
	case FRKey::COUNT:
		break;
	default:
		break;
	}
}

void MyFramework::onKeyReleased(FRKey k)
{
	if (!m_player1)
		return;


	switch (k)
	{
	case FRKey::RIGHT:
	case FRKey::LEFT:
		m_player1->setXSpeed(0);
		m_player1->setYSpeed(0);
		break;
	case FRKey::DOWN:
	case FRKey::UP:
		m_player1->setXSpeed(0);
		m_player1->setYSpeed(0);
		break;
	case FRKey::COUNT:
		break;
	default:
		break;
	}
}

const char* MyFramework::GetTitle()
{
	return "HrabetsBattleCity";
}

void MyFramework::render()
{
	// Draw all game objects
	int objectsCount = 0;
	for (int i = 0; i < kObjectsCountMax; i++)
		if (m_objects[i] != 0)
		{
			m_objects[i]->render();
			objectsCount++;
		}
}

void MyFramework::update(float dt)
{
	for (int i = 0; i < kObjectsCountMax; i++)
		if (m_objects[i] != 0)
		{
			m_objects[i]->update(dt);

			if (m_objects[i]->getHealth() <= 0 && m_objects[i]->getDestroyAfterDeath())
				destroyObject(m_objects[i]);
		}

	// Base destroyed
	if (m_base && m_base->getHealth() <= 0)
		Init();

	// Player1 destroyed
	if (m_player1 && m_player1->getHealth() <= 0)
	{
		destroyObject(m_player1);
		m_player1 = NULL;
	}

	// All enemies destroyed
	if (m_diedEnemiesCount == kEnemiesPerLevel)
		Init();
}

GameObject* MyFramework::checkIntersects(float x, float y, float width, float height, GameObject* exceptObject)
{
	int r00 = int(y);
	int c00 = int(x);
	int r01 = r00 + height - 1;
	int c01 = c00 + width - 1;

	for (int i = 0; i < kObjectsCountMax; i++)
		if (m_objects[i] != 0 && m_objects[i]->getPhysical() && m_objects[i] != exceptObject)
		{
			int r10 = int(m_objects[i]->getY());
			int c10 = int(m_objects[i]->getX());
			int r11 = r10 + m_objects[i]->getHeight() - 1;
			int c11 = c10 + m_objects[i]->getWidth() - 1;

			if (r00 <= r11 && r01 >= r10 && c00 <= c11 && c01 >= c10)
				return m_objects[i];
		}

	return 0;
}

bool MyFramework::moveObjectTo(GameObject* object, float x, float y)
{
	int r0 = int(y);
	int c0 = int(x);
	int r1 = r0 + object->getHeight() - 1;
	int c1 = c0 + object->getWidth() - 1;

	if (r0 < 0 || c0 < 0 || r1 >= kLevelRows || c1 >= kLevelColumns)
		return false;


	bool canMoveToCell = false;

	GameObject* otherObject = checkIntersects(x, y, object->getWidth(), object->getHeight(), object);
	//Fix later
	 /*GameObjectType  obj = object->getType();
	 if (obj == GameObjectType_BuffTank)
	 {
		 object.m_health = 0;
		 canMoveToCell = true;
	 }
	 */
	 if (otherObject)
		object->intersect(otherObject);
	 else
		canMoveToCell = true;


	if (canMoveToCell)
	{
		object->setX(x);
		object->setY(y);
	}

	return canMoveToCell;
}

int MyFramework::getObjectsCount(GameObjectType type)
{
	int totalCount = 0;

	for (int i = 0; i < kObjectsCountMax; i++)
	{
		if (m_objects[i] == 0)
			continue;

		if (m_objects[i]->getType() == type)
			totalCount++;
	}

	return totalCount;
}

GameObject* MyFramework::createObject(GameObjectType type, float x, float y)
{
	// Find free pointer and create object
	for (int i = 0; i < kObjectsCountMax; i++)
	{
		if (m_objects[i] == 0)
		{
			GameObject* object = 0;

			switch (type)
			{
			case GameObjectType_Wall:			       object = new Wall();			break;
			case GameObjectType_Base:			       object = new Base();			break;
			case GameObjectType_Bullet:			     object = new Bullet();			break;
			case GameObjectType_TankPlayer:		   object = new TankPlayer();		break;
			case GameObjectType_TankEnemy:		   object = new TankEnemy();		break;
			case GameObjectType_EnemySpawner:	   object = new EnemySpawner();	break;
			case GameObjectType_PowerUpSpawner:  object = new PowerUpSpawner(); break;
			case GameObjectType_BuffTank:        object = new BuffTank(); break;
			}

			if (object == 0)
				return 0;

			object->setGame(this);

			if (moveObjectTo(object, x, y) == false)
			{
				delete object;
				return 0;
			}

			m_objects[i] = object;

			return object;
		}
	}

	return 0;
}

void MyFramework::destroyObject(GameObject* object)
{
	for (int i = 0; i < kObjectsCountMax; i++)
	{
		if (m_objects[i] == object)
		{
			delete m_objects[i];
			m_objects[i] = 0;

			return;
		}
	}
}

void MyFramework::increaseDiedEnemiesCount()
{
	m_diedEnemiesCount++;
}