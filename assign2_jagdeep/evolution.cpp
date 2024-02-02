#include "evolution.h"

//function use to update the cell_array in the evolution loop  
void update_cell_array(Cells& cell, int num_cells) {
    Cells newcell = std::make_unique<bool[]>(num_cells);
    for (int i = 0; i < num_cells; i++)
        newcell[i] = next_cell_state(cell, i, num_cells);
    std::swap(cell, newcell);
}

// Determine next state of a single cell based on the state of all the cells
//this function is used in the update_cell_array
//required includes are in the evolution.h header file

bool next_cell_state(const Cells& cell_state, int cell_index, int num_cells) {
   
  // the modulus operator (%) enforces periodic boundary conditions

    int alive_neighbours = 0;
    for (int j = 1; j <= 2; j++) {
        if (cell_state[(cell_index+j+num_cells)%num_cells] == alive)
            alive_neighbours++;
        if (cell_state[(cell_index-j+num_cells)%num_cells] == alive)
            alive_neighbours++;
    }
    if (cell_state[cell_index] == alive  and
        (alive_neighbours == 2 or alive_neighbours == 4))
        return alive;
    else if (cell_state[cell_index] == dead  and
               (alive_neighbours == 2 or alive_neighbours == 3))
        return alive;
    else
        return dead;
}    

