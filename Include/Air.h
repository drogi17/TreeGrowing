#pragma once

#include <SFML/Graphics.hpp>

class Air {
private:

	int m_humidity; 	// 0 .. 100
	int m_temperature; 	// -20 .. 60

	sf::Color 	m_color;
	bool 		m_updated;

public:

	Air ();

	int getHumidity () const { return m_humidity; }
	int getTemperature () const { return m_temperature; }
	float getTemperaturePercentage ();
	sf::Color getColor () const { return m_color; } 
	bool isUpdated () const { return m_updated; }

	void update ();

private:

	void update_color ();

};