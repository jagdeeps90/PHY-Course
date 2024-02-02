#include "initialize_cells.h"

void fill_cells(Cells& cell, int& num_cells, double& target_alive_fraction){

double fill = 0.0;
    for (int i = 0; i < num_cells; i++) {
        fill += target_alive_fraction;
        if (fill >= 1.0) {
            cell[i] = alive;
            fill -= 1.0;
        } else
            cell[i] = dead;
    }

}
