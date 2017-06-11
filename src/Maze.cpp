#include "Maze.hpp"

Maze::Maze(int num_rows, int num_cols)
    : p_cols(num_cols)
{
    p_grid.reserve(num_rows*num_cols);

    for(int i = 0; i < num_rows; ++i) {
        for(int j = 0; j < num_cols; ++j) {
            p_grid.emplace_back(Cell(i, j, 30));
        }
    }
}

auto Maze::draw(const ALLEGRO_COLOR& fill,
                const ALLEGRO_COLOR& line) const -> void {
    for(auto& cell : p_grid) {
        cell.draw(fill, line);
    }
}

auto Maze::remove_walls_between(const int cell1_r, const int cell1_c,
                                const int cell2_r, const int cell2_c) -> void {
    auto& cell1 = cell_at(cell1_r, cell1_c);
    auto& cell2 = cell_at(cell2_r, cell2_c);

    auto row_diff = cell1_r - cell2_r;
    auto col_diff = cell1_c - cell2_c;

    if(col_diff > 0) {
        cell1.remove_wall(Pos::Left);
        cell2.remove_wall(Pos::Right);
    } else if(col_diff < 0) {
        cell1.remove_wall(Pos::Right);
        cell2.remove_wall(Pos::Left);
    } else if(row_diff > 0) {
        cell1.remove_wall(Pos::Top);
        cell2.remove_wall(Pos::Bottom);
    } else if(row_diff < 0) {
        cell1.remove_wall(Pos::Bottom);
        cell2.remove_wall(Pos::Top);
    }
}

auto Maze::cell_at(const int i, const int j) -> Cell& {
    return p_grid[i + j*p_cols];
}
