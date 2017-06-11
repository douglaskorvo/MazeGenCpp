#include <iostream>

#include "Game.hpp"

auto main(int, char**) -> int {
    try {
        Game game(300, 300);
        game.run();
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}
