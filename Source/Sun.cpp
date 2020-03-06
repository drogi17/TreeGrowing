#include "Sun.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

Sun::Sun () 
: m_warm(DEFAULT_WARM), m_brightness(DEFAULT_BRIGHTNESS) 
{}

void Sun::update () {
	ImGui::Begin("Sun");
	if (ImGui::SliderInt("Warm", &m_warm, MIN_WARM, MAX_WARM))
		m_drawable.update_warm(m_warm);
	ImGui::SliderInt("Brightness", &m_brightness, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
	ImGui::End();
}

void Sun::draw (RenderWindow &window) {
	m_drawable.draw(window);
}