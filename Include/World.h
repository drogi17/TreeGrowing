#pragma once

#include <SFML/Graphics.hpp>

#include "Air.h"
#include "Soil.h"

class World {
private:

	Air 				m_air;
	Soil 				m_soil;
	sf::Clock 			m_deltaClock;
	sf::RenderWindow 	m_window;

public:

	World ();
	~World ();

	bool exists () { return m_window.isOpen(); }

	void update ();
	void draw ();
};