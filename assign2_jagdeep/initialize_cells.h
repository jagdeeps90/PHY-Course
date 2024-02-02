#ifndef INITIALIZE_CELLS_H
#define INITIALIZE_CELLS_H

#include <memory>
#include <iostream>

const bool alive = true;
const bool dead = false;

using Cells = std::unique_ptr<bool[]>;

void fill_cells(Cells& cell, int& num_cells, double& target_alive_fraction);

#endif // INITIALIZE_CELLS_H
