#include "Tree.h"
#include "Confines.h"

#include "imgui.h"
#include "imgui-SFML.h"

using namespace sf;

Tree::Tree () 
: m_growth(0.f)
{}

void Tree::update (Air &air, Ground &ground, Sun &sun) {

}

void Tree::draw (RenderWindow &window) {
	//m_drawable.draw(window);
}
