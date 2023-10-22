#pragma once

#include <raylib.h>

class Bullet
{
public:
	Bullet(Vector2 p_origin, Vector2 p_vel, Texture2D p_tex);
	Bullet(Vector2 p_origin, Texture2D p_tex);
	void render();
	void move();
private:
	Vector2 pos;
	Vector2 vel;
	Texture2D tex;
};