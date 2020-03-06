#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class SunDrawer {
private:

	std::vector<sf::CircleShape> m_circles;

public:

	SunDrawer ();

	void update_warm (int warm);
	void update_brightness (int brightness);
	void draw (sf::RenderWindow &window);

private:

	float compute_radius (int index);

};

