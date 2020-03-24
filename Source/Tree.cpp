#include "Tree.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

Tree::Tree (Vector2f position) 
: 
  m_required(24.f, 35.f, 15.f),
  m_ration(13.f, 15.f, 12.f),
  m_growingRate(0.001),
  m_growth(1.f),
  m_dead(false),
  m_drawable(position)
{
	m_leaves.setOrigin(position);
}

void Tree::update (Air &air, Ground &ground, Sun &sun) {
	if (m_growth < 15.f) m_collected = m_required.multiply(m_growth * 10.f);
	else collect_resources(air, ground, sun);

	distribute_resources();

	consume();
	check_life();
	if (m_drawable.update(m_growth))
		m_leaves.generatePosition(m_drawable.getShape());
	m_leaves.update(m_growth);
}

void Tree::draw (RenderWindow &window) {
	m_drawable.draw(window);
	m_leaves.draw(window);
}

void Tree::collect_resources (Air &air, Ground &ground, Sun &sun) {
	m_collected.add(m_leaves.collect(air, sun));
	//m_collected = m_leaves.collect(air, sun);
	m_collected.water += ground.getHumidity() * m_growth;
	m_collected.materials += ground.getMinerals() * m_growth;
}

void Tree::distribute_resources () {
	m_resources.add(m_collected.subtract(m_required.multiply(m_growth / 100.f + 1)));
	m_leaves.feed(m_collected);
	m_leaves.grow(m_collected, m_growth, m_drawable.getShape());
	float k = m_growth / 100.f;
	while (m_collected.check_capacity((m_required.multiply(m_growth / 100.f + 1)).multiply(k))) {
		m_collected.subtract((m_required.multiply(m_growth / 100.f + 1)).multiply(k));
		m_growth += m_growingRate;
	}
	m_resources.add(m_collected);
}

void Tree::consume () {
	m_resources.subtract(m_ration.multiply(m_growth / 100.f + 1));
}

void Tree::check_life () {
	if (!m_resources.water || !m_resources.energy || !m_resources.materials)
		m_dead = true;
}
