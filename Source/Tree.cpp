#include "Tree.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

Tree::Tree (Vector2f position) 
: m_drawable(position), m_growth(0.f)
{}

void Tree::update (Air &air, Ground &ground, Sun &sun) {
	if (m_growth < 100.f) {
		m_growth += 0.1f;
	}
	m_drawable.update(m_growth);
}

void Tree::draw (RenderWindow &window) {
	m_drawable.draw(window);
}
