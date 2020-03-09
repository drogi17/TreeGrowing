#include "SunDrawer.h"
#include "Confines.h"
#include <iostream>

using namespace sf;
using namespace std;

SunDrawer::SunDrawer () {
	CircleShape circle;
	circle.setRadius(SUN_RADIUS);
	circle.setOrigin(circle.getRadius(),circle.getRadius());
	circle.setPosition(Vector2f(75.f, 75.f));
	circle.setFillColor(Color(240, 160, 50));
	for (int i = 0; i < RAYS_NUMBER; i++)
		m_circles.push_back(circle);
}

void SunDrawer::update_warm (int warm) {
	float k = (float)(-MIN_WARM + warm) / (MAX_WARM - MIN_WARM);
	Color color = Color(
		SUN_COLOR_RED,
		SUN_COLOR_GREEN + (225 - SUN_COLOR_GREEN) * k,
		SUN_COLOR_BLUE + (210 - SUN_COLOR_BLUE) * k,
		MAX_ALPHA
	);
	for (auto &circle : m_circles) {
		circle.setFillColor(color);
		color.a /= Q_COEFFICIENT;
	}
}

void SunDrawer::update_brightness (int brightness) {
	float k = (float)(-MIN_BRIGHTNESS + brightness) / (MAX_BRIGHTNESS - MIN_BRIGHTNESS);
	float radius = k * (compute_radius(RAYS_NUMBER) - SUN_RADIUS) + SUN_RADIUS;
	for (int i = 0; i < m_circles.size(); i++) {
		m_circles[i].setRadius(compute_radius(i+1));
		if (radius < m_circles[i].getRadius())
			m_circles[i].setRadius(radius);
		m_circles[i].setOrigin(m_circles[i].getRadius(), m_circles[i].getRadius());
	}
}

void SunDrawer::draw (RenderWindow &window) {
	for (auto &circle : m_circles)
		window.draw(circle);
}

float SunDrawer::compute_radius (int index) {
	float r = SUN_RADIUS;
	for (int i = 1; i < index; i++) {
		r *= Q_COEFFICIENT;
	}
	return r;
}
