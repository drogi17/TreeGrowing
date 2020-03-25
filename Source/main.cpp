#include "World.h"

using namespace sf;

int main() {
    World world;

    while (world.exists()) {
        world.update();
        world.draw();
    }
}
