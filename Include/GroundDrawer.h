#pragma once

#include <SFML/Graphics.hpp>
#include "Air.h"

class GroundDrawer {
private:
	
	sf::Texture 	m_texture;
	sf::Sprite 		m_sprite;
	int 			m_state;

public:

	GroundDrawer ();
	
	void update (sf::RenderWindow &window, Air &air);
	void draw (sf::RenderWindow &window);

private:

	void set_texture (std::string file, sf::RenderWindow &window);

};