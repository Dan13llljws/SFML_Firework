#ifndef PARTICLE_H
#define PARTICLE_H

#include "Constants.h"
#include "SFML/Graphics.hpp"

const int PARTICLE_VELOCITY_MIN = 10;
const int PARTICLE_VELOCITY_MAX = 100;
const int PARTICLE_COUNT_MIN = 50;
const int PARTICLE_COUNT_MAX = 150;
const int PARTICLE_SIZE_MIN = 1;
const int PARTICLE_SIZE_MAX = 4;
const float PARTICLE_LIFE_MIN = 1;
const float PARTICLE_LIFE_MAX = 3;
const sf::Color PARTICLE_COLOR[5] = { sf::Color::Cyan, sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Yellow };

bool insideWindow(float x, float y);

class Particle
{
private:
	float x, y, vx, vy, life, age;
	int size;
	sf::Color color;

public:
	Particle(float x, float y, int size);
	bool update(float time);
	void render(sf::RenderWindow& win);
	void setColor(sf::Color color);
	void setLife(float life);
};

#endif
