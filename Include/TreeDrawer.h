#pragma once

#include <SFML/Graphics.hpp>
#include "PlantShape.h"

class TreeDrawer {
private:

	PlantShape 	m_tree;
	int 	 	m_shapes;
	int 		m_current;
	float 		m_step;
	std::string	m_path;

public:

	TreeDrawer (sf::Vector2f positoin);

	void update (float growth);
	void draw (sf::RenderWindow &window);

};