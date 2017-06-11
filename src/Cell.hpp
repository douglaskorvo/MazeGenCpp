#pragma once

#include <allegro5/allegro.h>

enum class Pos {
    Top,
    Right,
    Bottom,
    Left
};

class Cell {
public:
    Cell(int i, int j, float size);

    Cell(int i, int j, float width, float height);

    auto draw(const ALLEGRO_COLOR& fill,
              const ALLEGRO_COLOR& line) const -> void;

    auto remove_wall(const Pos& wall) -> void;

private:
    float p_x1, p_y1, p_x2, p_y2, p_wall_size;

    struct {
        bool top, right, bottom, left;
    } p_walls;
};
