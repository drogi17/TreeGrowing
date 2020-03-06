#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class SunDrawer {
private:

	std::vector<sf::CircleShape> m_circles;

public:

	SunDrawer ();

	void update_warm (int warm);
	void draw (sf::RenderWindow &window);

};

