#include "GroundDrawer.h"
#include "Confines.h"
#include <iostream>
#include <random>

using namespace sf;
using namespace std;

GroundDrawer::GroundDrawer ()
: m_surface(sf::TriangleStrip), m_soil(sf::TriangleStrip)
{ 	srand(time(NULL)); }
	
void GroundDrawer::generate_mesh (RenderWindow &window) {
	float median = window.getSize().y * GROUND_SIZE;
	float x_step = window.getSize().x / DOTS_NUMBER;
	float x_range = x_step - x_step * 0.3;
	float y_step = window.getSize().y * HILL_SIZE;
	float y_range = y_step;

	float N = window.getSize().x;
	float Y = window.getSize().y;
	Vector2f point;
	for (float x_start = 0; x_start < N; x_start += x_step) {
		point = generate_point(
			x_start, x_start + x_step, x_range,
			median - y_step, median, y_range
		);
		m_surface.append(Vertex(point));
		m_surface.append(Vertex(Vector2f(point.x, Y)));
		m_soil.append(Vertex(Vector2f(point.x, point.y + y_range)));
		m_soil.append(Vertex(Vector2f(point.x, Y)));
	}
	
	m_surface[0].position.x = 0;
	m_surface[1].position.x = 0;
	m_surface[m_surface.getVertexCount()-1].position.x = N;
	m_surface[m_surface.getVertexCount()-2].position.x = N;
	
	m_soil[0].position.x = 0;
	m_soil[1].position.x = 0;
	m_soil[m_soil.getVertexCount()-1].position.x = N;
	m_soil[m_soil.getVertexCount()-2].position.x = N;

}

void GroundDrawer::generate_minerals (RenderWindow &window) {
	CircleShape mineral;
	mineral.setRadius(5.f);
	mineral.setPointCount(4);
	mineral.setOrigin(mineral.getRadius(), mineral.getRadius());

	vector<Color> colors = {
		Color(158, 116, 68),
		Color(168, 85, 77),
		Color(149, 155, 171)
	};

	float y_start = window.getSize().y * (GROUND_SIZE + HILL_SIZE) + mineral.getRadius();
	float y_end = window.getSize().y;
	float y_range = y_end - y_start;
	float x_end = window.getSize().x;

	for (int i = 0; i < 100; i++) {
		mineral.setRotation(rand()%360);
		mineral.setPosition(generate_point(
			0.f, x_end, x_end,
			y_start, y_end, y_range
		));
		mineral.setFillColor(colors[rand()%colors.size()]);
		m_minerals.push_back(mineral);
	}
}

void GroundDrawer::update_color (Air &air) {
	int t = air.getTemperature();
	/*Color surface_color(86, 125, 70);
	Color soil_color(54, 35, 18);*/

	/*Color surface_color(255, 250, 250);
	Color soil_color(182, 211, 240);
	Color soil_color(129, 108, 91);*/

	/*Color surface_color(212, 182, 128);
	Color soil_color(112, 70, 42);*/

	Color surface_color;
	Color soil_color;
	if (t <= (MAX_TEMPERATURE - MIN_TEMPERATURE)/2 + MIN_TEMPERATURE) {
		float k = (float)(-MIN_TEMPERATURE + t) / (MAX_TEMPERATURE - MIN_TEMPERATURE) * 2;
		surface_color = Color(
			255.f + (86.f - 255.f) * k,
			250.f + (125.f - 250.f) * k,
			250.f + (70.f - 250.f) * k
		);
		soil_color = Color(
			129.f + (54.f - 129.f) * k,
			108.f + (35.f - 108.f) * k,
			91.f + (18.f - 91.f) * k
		);
	} else {
		float k = ((float)(-MIN_TEMPERATURE + t) / (MAX_TEMPERATURE - MIN_TEMPERATURE) - 0.5f) * 2;
		surface_color = Color(
			86.f + (212.f - 86.f) * k,
			125.f + (182.f - 125.f) * k,
			70.f + (128.f - 70.f) * k
		);
		soil_color = Color(
			54.f + (112.f - 54.f) * k,
			35.f + (70.f - 35.f) * k,
			18.f + (42.f - 18.f) * k
		);
	}

	for (int i = 0; i < m_surface.getVertexCount(); i++)
		m_surface[i].color = surface_color;
	for (int i = 0; i < m_soil.getVertexCount(); i++)
		m_soil[i].color = soil_color;
	
}

void GroundDrawer::draw (RenderWindow &window, int minerals) {
	window.draw(m_surface);
	window.draw(m_soil);
	float k = (float)(-MIN_MINERALS + minerals) / (MAX_MINERALS - MIN_MINERALS);
	int N = m_minerals.size() * k;
	for (int i = 0; i < N; i++)
		window.draw(m_minerals[i]);
}

Vector2f GroundDrawer::generate_point (float x_start, float x_end, float x_range, 
									   float y_start, float y_end, float y_range) {
	Vector2f point = Vector2f(rand()%(int)x_range, rand()%(int)y_range);
	point.x += (abs(x_start - x_end) - x_range) / 2 + x_start; 
	point.y += (abs(y_start - y_end) - y_range) / 2 + y_start; 
	return point;
}










