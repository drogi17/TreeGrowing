#pragma once

#include <SFML/Graphics.hpp>
#include "SoilDrawable.h"
#include "Air.h"

class Soil {
private:
	
	int 			m_minerals; // 0 .. 100
	int 			m_humidity; // 0 .. 100
	SoilDrawable 	m_drawable;

public:

	Soil ();

	int getMinerals () const { return m_minerals; }
	int getHumidity () const { return m_humidity; }

	void update (sf::RenderWindow &window, Air &air);
	void draw (sf::RenderWindow &window);
};