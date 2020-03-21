#pragma once

#include <SFML/Graphics.hpp>

#include "GroundDrawer.h"
#include "Air.h"

class Ground {
private:
	
	int 			m_minerals; // 0 .. 100
	int 			m_humidity; // 0 .. 100
	GroundDrawer 	m_drawable;

public:

	Ground ();
	void setup (sf::RenderWindow &window, Air &air);

	int getMinerals () const { return m_minerals; }
	int getHumidity () const { return m_humidity; }

	void update (Air &air);
	void draw (sf::RenderWindow &window);
};