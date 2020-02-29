#include "Air.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

Air::Air () 
: m_humidity(DEFAULT_HUMIDITY), m_temperature(DEFAULT_TEMPERATURE) 
{}

sf::Color Air::getColor () {
	int k = BG_COLOR_CHANGE / (MAX_TEMPERATURE - MIN_TEMPERATURE) * (-MIN_TEMPERATURE + m_temperature);
	return sf::Color(BG_COLOR_RED + k, BG_COLOR_GREEN, BG_COLOR_BLUE - k);
}

void Air::update () {
	ImGui::Begin("Air");
	ImGui::SliderInt("Humidity", &m_humidity, MIN_HUMIDITY, MAX_HUMIDITY);
	ImGui::SliderInt("Temperature", &m_temperature, MIN_TEMPERATURE, MAX_TEMPERATURE);
	ImGui::End();
}