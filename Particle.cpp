#include "Particle.h"
#include "Constants.h"

Particle::Particle(float x, float y, int size)
{
	this->x = x;
	this->y = y;
	this->size = size;
	float ang = rand() % 360 * PI / 180;
	float vel = PARTICLE_VELOCITY_MIN + rand() % (PARTICLE_VELOCITY_MAX - PARTICLE_VELOCITY_MIN);
	vx = vel * cos(ang);
	vy = vel * sin(ang);
	age = 0;
}

bool insideWindow(float x, float y)
{
	return x > 0 && x < WINDOW_WIDTH && y > 0 && y < WINDOW_HEIGHT;
}

bool Particle::update(float time)
{

	age += time;
	if (age > life)
	{
		return false;
	}
	x = x + vx * time;
	y = y + vy * time + 0.5 * GRAVITY * time * time;
	vy = vy + GRAVITY * time;
	if (!insideWindow(x, y))
	{
		return false;
	}
	return true;
}

void Particle::render(sf::RenderWindow& win)
{
	sf::RectangleShape r(sf::Vector2f(size, size));
	r.setFillColor(color);
	r.setPosition(x, y);
	win.draw(r);
}

void Particle::setColor(sf::Color color)
{
	this->color = color;
}

void Particle::setLife(float life)
{
	this->life = life;
}