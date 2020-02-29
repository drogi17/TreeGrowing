#pragma once

#include <SFML/Graphics.hpp>

class Air {
private:

	int m_humidity; 	// 0 .. 100
	int m_temperature; 	// -20 .. 60

public:

	Air ();

	unsigned int getHumidity () const { return m_humidity; }
	unsigned int getTemperature () const { return m_temperature; }
	sf::Color getColor (); 

	void update ();

};