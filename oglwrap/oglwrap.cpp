/** @file oglwrap.cpp
    @brief A test file.
*/


#include <SFML/Window.hpp>
#include <GL/glew.h>
#include "oglwrap.hpp"
#include "shapes/cube.hpp"
#include "shapes/fullScreenRect.hpp"
#include "mesh/mesh.hpp"

using namespace oglwrap;

UniformBuffer buf;

int main() {
    sf::Window window(
        sf::VideoMode(800, 600), "Debug Context",
        sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3)
    );
    assert(glewInit() == GLEW_OK);

    buf.bindRange(2, -1, -1);
    buf.data(-1, (void*)0);

    Texture2D tex;
    tex.bind();
    tex.generateMipmap();

    return 0;
}


