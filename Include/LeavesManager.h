#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Leaf.h"
#include "PlantShape.h"

#include "Resources.h"

class LeavesManager {
private:

	std::vector<Leaf> 	m_leaves;
	sf::Vector2f 		m_origin;
	Resources 			m_required;
	float 				m_growingRate; // 50 / 33 = 1.5 листьев на 1 рост

public:

	LeavesManager ();

	Resources collect (Air &air, Sun &sun);
	void feed (Resources &resources);
	void grow (Resources &resources, float growth, PlantShape &shape);

	void setOrigin (sf::Vector2f origin);
	void generatePosition (PlantShape &shape);

	void update (float growth);
	void draw (sf::RenderWindow &window);

};