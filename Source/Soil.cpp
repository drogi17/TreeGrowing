#include "Soil.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

Soil::Soil () 
: m_humidity(DEFAULT_HUMIDITY), m_minerals(DEFAULT_MINERALS) 
{}

void Soil::update (RenderWindow &window, Air &air) {
	ImGui::Begin("Soil");
	ImGui::SliderInt("Minerals", &m_minerals, MIN_MINERALS, MAX_MINERALS);
	ImGui::SliderInt("Humidity", &m_humidity, MIN_HUMIDITY, MAX_HUMIDITY);
	ImGui::End();
	m_drawable.update(window, air);
}

void Soil::draw (RenderWindow &window) {
	m_drawable.draw(window);
}