#include "Game.hpp"

#include <allegro5/allegro_primitives.h>

#include "Maze.hpp"

using std::make_unique;

Game::Game(const int width, const int height)
    : p_size{width, height}
    , p_maze(nullptr)
    , p_game_state(Status::Initializing)
{
    if(!al_install_system(ALLEGRO_VERSION_INT, nullptr)) {
        throw "Allegro failed to initialize";
    }

    if(!al_install_keyboard()) {
        throw "Keyboard failed to install";
    }

    if(!al_init_primitives_addon()) {
        throw "Primitives addon failed to initialize";
    }

    p_display = al_create_display(p_size.w, p_size.h);
    if(!p_display) {
        throw "Failed to create display";
    }

    p_evnt_q = al_create_event_queue();
    if(!p_evnt_q) {
        throw "Failed to create event queue";
    }

    al_register_event_source(p_evnt_q, al_get_display_event_source(p_display));
    al_register_event_source(p_evnt_q, al_get_keyboard_event_source());

    p_maze = make_unique<Maze>(10, 10);
    p_game_state = Status::Running;
}

Game::~Game() noexcept {
    al_destroy_event_queue(p_evnt_q);
    al_destroy_display(p_display);

    al_shutdown_primitives_addon();

    al_uninstall_keyboard();
    al_uninstall_system();
}

auto Game::run() -> void {
    auto fill = al_map_rgb(255, 0, 0);
    auto line = al_map_rgb(0, 255, 0);
    auto running = true;

    p_maze->remove_walls_between(0, 0, 0, 1);

    while(running) {
        update();

        switch(p_game_state) {
        case Status::Quit:
            running = false;
            break;

        default:
            break;
        }

        draw(fill, line);
    }
}

auto Game::key_pressed(const int keycode) -> void {
    switch(keycode) {
    case ALLEGRO_KEY_Q:
        p_game_state = Status::Quit;
        break;

    case ALLEGRO_KEY_R:
        reset();
        break;

    default:
        break;
    }
}

auto Game::update() -> void {
    ALLEGRO_EVENT evnt;

    while(al_get_next_event(p_evnt_q, &evnt)) {
        switch(evnt.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            key_pressed(evnt.keyboard.keycode);
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            p_game_state = Status::Quit;
            break;

        default:
            break;
        }
    }
}

auto Game::draw(const ALLEGRO_COLOR& fill,
                const ALLEGRO_COLOR& line) const -> void {
    al_clear_to_color(al_map_rgb(255, 255, 255));

    p_maze->draw(fill, line);

    al_flip_display();
}

auto Game::reset() -> void {
    p_maze = make_unique<Maze>(10, 10);
}
