#include "output.h"


// Output time step, state of cells, and fraction of alive cells
void output_state(int timestep, const Cells& cell, int num_cells) {
    const char on_char = 'I', off_char = '-';
    double alive_fraction = 0.0;
    for (int i = 0; i < num_cells; i++)
        alive_fraction += cell[i];
    alive_fraction /= num_cells;
    std::cout << timestep << "\t";
    for (int i = 0; i < num_cells; i++)
        std::cout << (cell[i] == alive ? on_char : off_char);
    std::cout << " " << alive_fraction << "\n";
}

