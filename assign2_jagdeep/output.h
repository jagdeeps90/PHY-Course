#ifndef OUTPUT_H
#define OUTPUT_H

#include "initialize_cells.h"

using Cells = std::unique_ptr<bool[]>;
//interface
void output_state(int timestep, const Cells& cell, int num_cells);


#endif //OUTPUT_H
