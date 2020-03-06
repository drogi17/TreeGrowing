#include "SunDrawer.h"
#include "Confines.h"
#include <iostream>

using namespace sf;
using namespace std;

SunDrawer::SunDrawer () {
	CircleShape circle;
	circle.setRadius(20);
	circle.setOrigin(circle.getRadius(),circle.getRadius());
	circle.setPosition(Vector2f(75.f, 75.f));
	circle.setFillColor(Color(240, 160, 50));
	m_circles.push_back(circle);

}

void SunDrawer::update_warm (int warm) {
	float k = (float)(-MIN_WARM + warm) / (MAX_WARM - MIN_WARM);
	Color color = Color(
		SUN_COLOR_RED,
		SUN_COLOR_GREEN + (225 - SUN_COLOR_GREEN) * k,
		SUN_COLOR_BLUE + (210 - SUN_COLOR_BLUE) * k
	);
	m_circles.back().setFillColor(color);
}

void SunDrawer::draw (RenderWindow &window) {
	for (auto &circle : m_circles)
		window.draw(circle);
}

