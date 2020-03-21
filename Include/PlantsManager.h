#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Seed.h"
#include "Tree.h"
#include "Air.h"
#include "Ground.h"
#include "Sun.h"

class PlantsManager {
private:

    std::vector<Tree> 	m_trees;
    Seed 				m_seed;

public:
    PlantsManager ();

    void setup (sf::RenderWindow &window);

    void click () { m_seed.click(); }

    void update (Air &air, Ground &ground, Sun &sun, sf::Vector2f mousePosition);
    void draw (sf::RenderWindow &window);
};