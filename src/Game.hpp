#pragma once

#include <memory>

#include <allegro5/allegro.h>

#include "Maze.hpp"

class Game {
public:
    Game(int width, int height);

    ~Game() noexcept;

    auto run() -> void;

private:
    enum class Status {
        Initializing,
        Quit,
        Running,
    };

    struct {
        int w, h;
    } p_size;

    ALLEGRO_DISPLAY       *p_display;
    ALLEGRO_EVENT_QUEUE   *p_evnt_q;
    std::unique_ptr<Maze>  p_maze;
    Status                 p_game_state;

    auto key_pressed(const int keycode) -> void;

    auto update() -> void;

    auto draw(const ALLEGRO_COLOR& fill,
              const ALLEGRO_COLOR& line) const -> void;

    auto reset() -> void;
};
