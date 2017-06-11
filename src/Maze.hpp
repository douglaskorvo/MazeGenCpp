#pragma once

#include <vector>

#include "Cell.hpp"

using std::vector;

class Maze {
public:
    Maze(int num_rows, int num_cols);

    auto draw(const ALLEGRO_COLOR& fill,
              const ALLEGRO_COLOR& line) const -> void;

    auto remove_walls_between(const int cell1_i, const int cell1_j,
                              const int cell2_i, const int cell2_j) -> void;

private:
    int p_cols;
    vector<Cell> p_grid;

    auto cell_at(const int i, const int j) -> Cell&;
};
