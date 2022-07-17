#include "Firework.h"

int main()
{
	sf::RenderWindow win(sf::VideoMode(800, 400), "Double Pendulum");
	win.setFramerateLimit(FPS);

	std::vector<Firework> fire;

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				win.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i p = sf::Mouse::getPosition(win);
					std::cout << p.x << ' ' << p.y << std::endl;
					fire.push_back(Firework(p.x, p.y));
				}
			}
		}

		for (auto it = fire.begin(); it != fire.end();)
		{
			if (it->update(1.0 / FPS))
			{
				it++;
			}
			else
			{
				fire.erase(it);
			}
		}

		win.clear(sf::Color::Black);

		for (auto f : fire)
		{
			f.render(win);
		}

		win.display();
	}
}
