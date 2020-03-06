#include "GroundDrawer.h"
#include <iostream>

using namespace sf;
using namespace std;

GroundDrawer::GroundDrawer ()
: m_state(0)
{}

void GroundDrawer::update (RenderWindow &window, Air &air) {
	int t = air.getTemperature();
	if (t <= 0) {
		if (m_state != -1) {
			m_state = -1;
			set_texture("Textures/cold.png", window);
		}
	} else if (t <= 40) {
		if (m_state != 1) {
			m_state = 1;
			set_texture("Textures/warm.png", window);
		}
	} else 
		if (m_state != 2) {
			m_state = 2;
			set_texture("Textures/hot.png", window);
		}
}

void GroundDrawer::draw (RenderWindow &window) {
	window.draw(m_sprite);
}

void GroundDrawer::set_texture (string file, RenderWindow &window) {
	m_texture.loadFromFile(file);
	m_sprite.setTexture(m_texture);
	float scale = (float)window.getSize().x / m_texture.getSize().x;
	m_sprite.setScale(scale, scale);
	m_sprite.setTextureRect(IntRect(0, 0, (int)m_sprite.getLocalBounds().width, (int)(window.getSize().y * 0.2 / scale)));
	m_sprite.setPosition(Vector2f(0.f, window.getSize().y - m_sprite.getGlobalBounds().height));
}











