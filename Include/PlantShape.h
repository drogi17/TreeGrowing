#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes/ConcaveShape.hpp>

class PlantShape : public thor::ConcaveShape {
private:

	sf::Vector2f 	mOrigin;
	sf::Vector2f 	mPosition;
	float 			mScale;

public:

	PlantShape ();

	sf::Vector2f getOrigin () const { return mOrigin; } 
	void setOrigin (sf::Vector2f origin) { mOrigin = origin; }

	float getScale () const { return mScale; }
	void setScale (float k);
	void scale (float k) { setScale(mScale * k); }

	void setPosition (sf::Vector2f position);
	sf::Vector2f getPosition () const { return mPosition; }

	void loadFromFile (std::string file);

};