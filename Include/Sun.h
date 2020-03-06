#pragma once

#include <SFML/Graphics.hpp>
#include "SunDrawer.h"

class Sun {
private:
	
	int 			m_warm; // 0 .. 100
	int 			m_brightness; // 0 .. 100
	SunDrawer 		m_drawable;

public:

	Sun ();

	int getWarm () const { return m_warm; }
	int getBrightness () const { return m_brightness; }

	void update ();
	void draw (sf::RenderWindow &window);
};