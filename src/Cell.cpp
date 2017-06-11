#include "Cell.hpp"

#include <allegro5/allegro_primitives.h>

Cell::Cell(int i, int j, float size)
    : Cell(i, j, size, size)
{}

Cell::Cell(int i, int j, float width, float height)
    : p_x1(i*width)
    , p_y1(j*height)

    , p_x2(p_x1 + width)
    , p_y2(p_y1 + height)

    , p_wall_size(2)

    , p_walls{true, true, true, true}
{}

auto Cell::draw(const ALLEGRO_COLOR& fill,
                const ALLEGRO_COLOR& line) const -> void {
    al_draw_filled_rectangle(p_x1, p_y1, p_x2, p_y2, fill);

    if(p_walls.top)
        al_draw_line(p_x1, p_y1, p_x2, p_y1, line, p_wall_size);

    if(p_walls.right)
        al_draw_line(p_x2, p_y1, p_x2, p_y2, line, p_wall_size);

    if(p_walls.bottom)
        al_draw_line(p_x2, p_y2, p_x1, p_y2, line, p_wall_size);

    if(p_walls.left)
        al_draw_line(p_x1, p_y2, p_x1, p_y1, line, p_wall_size);
}

auto Cell::remove_wall(const Pos& wall) -> void {
    switch(wall) {
    case Pos::Top:
        p_walls.top = false;
        break;

    case Pos::Right:
        p_walls.right = false;
        break;

    case Pos::Bottom:
        p_walls.bottom = false;
        break;

    case Pos::Left:
        p_walls.left = false;
        break;
    }
}
