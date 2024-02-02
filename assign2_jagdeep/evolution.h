#ifndef EVOLUTION_H
#define EVOLUTION_H

#include "initialize_cells.h"

using Cells = std::unique_ptr<bool[]>;

//interface
void update_cell_array(Cells& cell, int num_cells);

bool next_cell_state(const Cells& cell_state, int cell_index, int num_cells);

#endif //EVOLUTION_H
