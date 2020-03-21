#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Seed {
private:

	sf::ConvexShape	m_seed;
	std::string 	m_plant;
	float 		 	m_bottom;
	bool 			m_active;
	bool 			m_falling;

	float 			m_step;

public:

	Seed ();

	void setPlant (std::string name);
	void setBottom (float y) { m_bottom = y; }
	std::string getPlant () { return m_plant; }
	sf::Vector2f getPosition () { return sf::Vector2f(m_seed.getPosition().x, m_bottom); }

	bool isActive () { return m_active; }
	void click () { if (m_active) m_falling = true; }

	bool update (sf::Vector2f mousePosition);
	void draw (sf::RenderWindow &window);

};