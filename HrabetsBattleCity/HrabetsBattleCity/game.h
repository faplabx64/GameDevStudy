#pragma once


/////////////////////////////////////
// Include

#include "Framework.h"
#include "gameObject.h"
#include "gameObjectType.h"

/////////////////////////////////////
// Constants
const int kObjectsCountMax = 1024;

/////////////////////////////////////
// Forward declaration
class GameObject;
class TankPlayer;

/* Test Framework realization */
class MyFramework : public Framework {

public:
	MyFramework();
	~MyFramework();

	virtual void PreInit(int& width, int& height, bool& fullscreen);

	virtual bool Init();

	virtual void Close();

	virtual bool Tick();

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);

	virtual const char* GetTitle() override;

	GameObject* createObject(GameObjectType type, float x, float y);
	void destroyObject(GameObject* object);
	GameObject* checkIntersects(float x, float y, float width, float height, GameObject* exceptObject);
	bool moveObjectTo(GameObject* object, float x, float y);
	int getObjectsCount(GameObjectType type);

	int getDiedEnemiesCount() { return m_diedEnemiesCount; }
	void increaseDiedEnemiesCount();

private:
	void render();
	void update(float dt);

private:
	bool m_isGameActive;
	unsigned int m_clockLastFrame;

	GameObject* m_objects[kObjectsCountMax];

	GameObject* m_base;
	TankPlayer* m_player1;

	int m_diedEnemiesCount;
};