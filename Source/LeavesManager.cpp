#include "LeavesManager.h"

using namespace sf;
using namespace std;

LeavesManager::LeavesManager () 
: m_required(10.f, 13.f, 16.f),
  m_growingRate(1.5)
{}

Resources LeavesManager::collect (Air &air, Sun &sun) {
	Resources collected;
	for (auto &leaf : m_leaves) {
		if (!leaf.isDead()) {
			collected.water += leaf.getWater(air, sun);
			collected.energy += leaf.getEnergy(air, sun);
		}
	}
	return collected;
}

void LeavesManager::feed (Resources &resources) {
	for (auto &leaf : m_leaves)
		if (!leaf.isDead())
			leaf.feed(resources);
}

// TODO: check if leaf will survive in next iteration
void LeavesManager::grow (Resources &resources, float growth, PlantShape &shape) {
	int limit = growth * m_growingRate;
	while (resources.check_capacity(m_required) && m_leaves.size() <= limit) {
		m_leaves.emplace_back(m_required, resources);
		m_leaves.back().generatePosition(shape);
	}
}

void LeavesManager::setOrigin (Vector2f origin) {
	m_origin = origin; // TODO: move leaves
}

void LeavesManager::generatePosition (PlantShape &shape) {
	for (auto &leaf : m_leaves)
		leaf.generatePosition(shape);
}

void LeavesManager::update (float growth) {
	for (int i = 0; i < m_leaves.size(); i++) {
		if (!m_leaves[i].isActive()) {
			m_leaves.erase(m_leaves.begin() + i);
			cout << m_leaves.size() << endl;
		}
		else
			m_leaves[i].update(growth);
	}
}

void LeavesManager::draw (RenderWindow &window) {
	for (auto &leaf : m_leaves)
		leaf.draw(window);
}
