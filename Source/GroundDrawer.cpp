#include "GroundDrawer.h"
#include <iostream>
#include <random>

using namespace sf;
using namespace std;

GroundDrawer::GroundDrawer ()
: m_surface(sf::TriangleStrip), m_soil(sf::TriangleStrip)
{}

void GroundDrawer::generate_mesh (RenderWindow &window, Air &air) {
	srand(time(NULL));

	float median = window.getSize().y * 0.9;
	float x_step = window.getSize().x / 30;
	float x_range = x_step;
	float y_step = window.getSize().y * 0.03;
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
	/*for (float x_start = 0; x_start < N; x_start += x_step) {
		m_surface.append(Vertex(generate_point(
			x_start, x_start + x_step, x_range,
			median - y_step, median, y_range
		)));
		m_surface.append(Vertex(Vector2f(m_surface[m_surface.getVertexCount()-1].position.x, Y)));
		m_soil.append(Vertex(generate_point(
			x_start, x_start + x_step, x_range,
			median, median + y_step, y_range
		)));
		m_soil.append(Vertex(Vector2f(m_soil[m_soil.getVertexCount()-1].position.x, Y)));
	}*/
	m_surface[0].position.x = 0;
	m_surface[1].position.x = 0;
	m_surface[m_surface.getVertexCount()-1].position.x = N;
	m_surface[m_surface.getVertexCount()-2].position.x = N;
	
	m_soil[0].position.x = 0;
	m_soil[1].position.x = 0;
	m_soil[m_soil.getVertexCount()-1].position.x = N;
	m_soil[m_soil.getVertexCount()-2].position.x = N;

}

void GroundDrawer::update_color (Air &air) {
	int t = air.getTemperature();
	Color surface_color(86, 125, 70);
	Color soil_color(54, 35, 18);
	for (int i = 0; i < m_surface.getVertexCount(); i++)
		m_surface[i].color = surface_color;
	for (int i = 0; i < m_soil.getVertexCount(); i++)
		m_soil[i].color = soil_color;
	
}

void GroundDrawer::draw (RenderWindow &window) {
	window.draw(m_surface);
	window.draw(m_soil);
}

Vector2f GroundDrawer::generate_point (float x_start, float x_end, float x_range, 
									   float y_start, float y_end, float y_range) {
	Vector2f point = Vector2f(rand()%(int)x_range, rand()%(int)y_range);
	point.x += (abs(x_start - x_end) - x_range) / 2 + x_start; 
	point.y += (abs(y_start - y_end) - y_range) / 2 + y_start; 
	cout << point.x << " " << point.y << endl;
	return point;
}










