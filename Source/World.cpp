#include "World.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

World::World () {
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	m_window.create(VideoMode::getDesktopMode(), "Plant Growing Simulation", Style::Fullscreen, settings);
	m_window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);
	m_ground.setup(m_window, m_air);
	m_plants.setup(m_window);
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
		if (event.type == Event::KeyPressed)
			if (event.key.code == Keyboard::Escape)
				m_window.close();
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Left)
				m_plants.click();
	}
	ImGui::SFML::Update(m_window, m_deltaClock.restart());

	m_air.update();
	m_ground.update(m_air);
	m_sun.update();
	m_plants.update(m_air, m_ground, m_sun, Vector2f(Mouse::getPosition(m_window)));
}

void World::draw () {
	m_window.clear(m_air.getColor());
	m_plants.draw(m_window);
	m_ground.draw(m_window);
	m_sun.draw(m_window);
	ImGui::SFML::Render(m_window);
	m_window.display();
}
