#include "Ground.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

Ground::Ground () 
: m_humidity(DEFAULT_HUMIDITY), m_minerals(DEFAULT_MINERALS) 
{}

void Ground::setup (RenderWindow &window, Air &air) {
	m_drawable.generate_mesh(window);
	m_drawable.generate_minerals(window);
	m_drawable.update_color(air);
}

void Ground::update (Air &air) {
	ImGui::Begin("Ground");
	ImGui::SliderInt("Minerals", &m_minerals, MIN_MINERALS, MAX_MINERALS);
	ImGui::SliderInt("Humidity", &m_humidity, MIN_HUMIDITY, MAX_HUMIDITY);
	ImGui::End();
	if (air.isUpdated())
		m_drawable.update_color(air);
}

void Ground::draw (RenderWindow &window) {
	m_drawable.draw(window, m_minerals);
}