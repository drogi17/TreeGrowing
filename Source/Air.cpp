#include "Air.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include <iostream>

Air::Air () 
: m_humidity(DEFAULT_HUMIDITY), m_temperature(DEFAULT_TEMPERATURE) 
{ update_color(); }

void Air::update () {
	m_updated = false;
	ImGui::Begin("Air");
	ImGui::SliderInt("Humidity", &m_humidity, MIN_HUMIDITY, MAX_HUMIDITY);
	if (ImGui::SliderInt("Temperature", &m_temperature, MIN_TEMPERATURE, MAX_TEMPERATURE))
		update_color();
	ImGui::End();
}

void Air::update_color () {
	m_updated = true;
	int k = BG_COLOR_CHANGE / (MAX_TEMPERATURE - MIN_TEMPERATURE) * (-MIN_TEMPERATURE + m_temperature);
	m_color =  sf::Color(BG_COLOR_RED + k, BG_COLOR_GREEN, BG_COLOR_BLUE - k);	
}