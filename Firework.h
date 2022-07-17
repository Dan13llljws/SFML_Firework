#ifndef FIREWORK_H
#define FIREWORK_H

#include "Constants.h"
#include "Particle.h"

class Firework
{
private:
	int particle_count;
	std::vector<Particle> particles;
	sf::Color color;

public:
	Firework(int x, int y);
	bool update(float time);
	void render(sf::RenderWindow& win);
};

#endif