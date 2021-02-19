#pragma once


/////////////////////////////////////
// Include
#include "direction.h"
#include "gameObjectType.h"
#include "game.h"
#include "rect.h"

class MyFramework;

/////////////////////////////////////
// Class GameObject
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void render();
	virtual void update(float dt);

	virtual void intersect(GameObject* object);

	GameObjectType getType() { return m_type; }

	void setGame(MyFramework* game) { m_game = game; }

	void setX(float x) { m_x = x; }
	float getX() { return m_x; }

	void setY(float y) { m_y = y; }
	float getY() { return m_y; }

	void setXSpeed(float xSpeed) { m_xSpeed = xSpeed; }
	float getXSpeed() { return m_xSpeed; }

	void setYSpeed(float ySpeed) { m_ySpeed = ySpeed; }
	float getYSpeed() { return m_ySpeed; }

	void setWidth(int width) { m_width = width; }
	int getWidth() { return m_width; }

	void setHeight(int height) { m_height = height; }
	int getHeight() { return m_height; }

	void setHealth(int health) { m_health = health; }
	int getHealth() { return m_health; }

	void setDestroyAfterDeath(bool destroyAfterDeath) { m_destroyAfterDeath = destroyAfterDeath; }
	bool getDestroyAfterDeath() { return m_destroyAfterDeath; }

	void setInvulnerable(bool invulnerable) { m_invulnerable = invulnerable; }
	bool getInvulnerable() { return m_invulnerable; }

	void setPhysical(bool physical) { m_physical = physical; }
	bool getPhysical() { return m_physical; }

	void setDirection(Direction direction) { m_direction = direction; }
	Direction getDirection() { return m_direction; }

	void doDamage(int damage);

	void setTextureRect(Rect rect) { m_spriteRect = rect; }

protected:
	MyFramework* m_game;
	GameObjectType m_type;

	float m_x;
	float m_y;
	float m_xSpeed;
	float m_ySpeed;

	int m_width;
	int m_height;

	int m_health;
	bool m_destroyAfterDeath;
	bool m_invulnerable;

	bool m_physical;

	Direction m_direction;

	Sprite* m_sprite;

	Rect m_spriteRect;
};
