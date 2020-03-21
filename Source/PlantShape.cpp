#include "PlantShape.h"

#include <fstream>

using namespace std;
using namespace sf;

PlantShape::PlantShape () 
: mOrigin(Vector2f(0.f, 0.f)), mScale(1.f)
{}

void PlantShape::setScale (float k) {
	for (int i = 0; i < getPointCount(); i++)
		setPoint(i, mOrigin + (getPoint(i) - mOrigin) * k / mScale);
	mScale = k;
}

void PlantShape::setPosition (Vector2f position) {
	Vector2f move = position - mOrigin;
	mOrigin += move;
	for (int i = 0; i < getPointCount(); i++)
		setPoint(i, getPoint(i) + move);
	mPosition = position;
}

void PlantShape::loadFromFile (std::string file) {
	ifstream fin(file);
	vector<Vector2f> verticies;
	Vector2f point;
	while (fin >> point.x >> point.y)
		verticies.push_back(point);
	setPointCount(verticies.size());
	for (int i = 0; i < verticies.size(); i++)
		setPoint(i, verticies[i]);
	mOrigin = Vector2f((getPoint(getPointCount()-1).x + getPoint(0).x)/2, getPoint(0).y);
	mScale = 1.f;
}

