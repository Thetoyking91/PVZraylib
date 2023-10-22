#include "Bullet.hpp"

Bullet::Bullet(Vector2 p_origin, Vector2 p_vel, Texture2D p_tex)
	:pos(p_origin),vel(p_vel),tex(p_tex)
{}

Bullet::Bullet(Vector2 p_origin, Texture2D p_tex)
	:pos(p_origin), vel(Vector2{1, 0}), tex(p_tex)
{}

void Bullet::render()
{
	DrawTexture(tex, pos.x - tex.width / 2, pos.y - tex.height / 2, WHITE);
}

void Bullet::move()
{
	pos.x += vel.x;
	pos.y += vel.y;
}