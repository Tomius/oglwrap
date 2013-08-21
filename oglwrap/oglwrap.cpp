#include <SFML/Window.hpp>
#include "oglwrap.hpp"
#include "texture.hpp"
#include "shapes/cube.hpp"
#include "shapes/fullScreenPic.hpp"
#include "shapes/mesh.hpp"

using namespace oglwrap;

int main() {
    sf::Window window(
        sf::VideoMode(800, 600), "Debug Context",
        sf::Style::Default, sf::ContextSettings(24, 8, 0, 3, 3)
    );
    assert(glewInit() == GLEW_OK);

    Texture2D tex;

    Texture1D tex1d(tex);

    return 0;
}


