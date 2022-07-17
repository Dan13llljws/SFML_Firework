#include "Firework.h"
#include "Constants.h"
#include "Particle.h"

Firework::Firework(int x, int y)
{
	particle_count = PARTICLE_COUNT_MIN + rand() % (PARTICLE_COUNT_MAX - PARTICLE_COUNT_MIN);
	color = PARTICLE_COLOR[rand() % 5];
	for (int i = 0; i < particle_count; i++)
	{
		Particle p(x, y, PARTICLE_SIZE_MIN + rand() % (PARTICLE_SIZE_MAX - PARTICLE_SIZE_MIN));
		p.setColor(color);
		p.setLife(PARTICLE_LIFE_MIN + (float)rand() / RAND_MAX * (PARTICLE_LIFE_MAX - PARTICLE_LIFE_MIN));
		particles.push_back(p);
	}
}

bool Firework::update(float time)
{
	for (std::vector<Particle>::iterator it = particles.begin(); it != particles.end();)
	{
		if (!it->update(time))
		{
			particles.erase(it);
		}
		else
		{
			it++;
		}
	}
	return (int)particles.size() > 0;
}

void Firework::render(sf::RenderWindow& win)
{
	for (auto par : particles)
	{
		par.render(win);
	}
}