#include "World.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

World::World () {
	m_window.create(VideoMode::getDesktopMode(), "Plant Growing Simulation");
	m_window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);
	m_ground.setup(m_window, m_air);
}

World::~World () {
	ImGui::SFML::Shutdown();
}

void World::update () {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(event);
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
	ImGui::SFML::Update(m_window, m_deltaClock.restart());

	m_air.update();
	m_ground.update(m_window, m_air);
	m_sun.update();
}

void World::draw () {
	m_window.clear(m_air.getColor());
	ImGui::SFML::Render(m_window);
	m_ground.draw(m_window);
	m_sun.draw(m_window);
	m_window.display();
}
