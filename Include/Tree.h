#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "TreeDrawer.h"
#include "Leaf.h"
#include "Air.h"
#include "Ground.h"
#include "Sun.h"

class Tree {
private:
	
	float 				m_water;
	float 				m_energy;
	float 				m_materials;
	float 				m_growth;

	std::vector<Leaf> 	m_leaves;
	TreeDrawer 			m_drawable;

public:

	Tree (sf::Vector2f position);

	void update (Air &air, Ground &ground, Sun &sun);
	void draw (sf::RenderWindow &window);
};