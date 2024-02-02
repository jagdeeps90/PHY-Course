/*
This program is a part of the course PHY1610
For compilation see the Makefile
use "make" to compile
*/

//----------------------------------------------------------------------------------------------------------
//initialize_cells.h part of the code is used to fills the cell array
//associated file is initialize_cell.cpp
#include "initialize_cells.h"

//---------------------------------------------------------------------------------------------------------
//evolution.h and evolution.cpp module of the code update the cell array in the evolution loop
#include "evolution.h"

//---------------------------------------------------------------------------------------------------------
/*
The code computes the time evolution for default {120} steps can be overwritten with commandline argument, 
and for each step, prints out
a line with a representation of the state and fraction of alive cells. associated modules are output.cpp and 
output.cpp
*/
#include "output.h"
//--------------------------------------------------------------------------------------------------------


//main program starts from here
int main(int argc, char* argv[]) {
   // Set default simulation parameters then can be adjusted by command line arguments
    int num_cells = 70;
    int num_steps = 120; 
    double target_alive_fraction = 0.35;
 
  //error handling part of the code:
    try {
        if (argc > 1)
            num_cells = std::stoi(argv[1]);
        if (argc > 2)
            num_steps = std::stoi(argv[2]);
        if (argc > 3)
            target_alive_fraction = std::stod(argv[3]);
    } catch(...) {
        std::cout <<
        "Computes a 1d version of Conway's game of life\n\n"
        "Usage:\n"
        "  gameof1d [-h | --help] | [NUMCELLS [NUMSTEPS [FRACTION]]]\n\n";
        if (std::string(argv[1]) != "-h" and std::string(argv[1]) !="--help") {
            std::cerr << "Error in arguments!\n";
            return 1;
        } else
            return 0;
    }
    //Simulation creation
    Cells cell(std::make_unique<bool[]>(num_cells));

    /*calls the function from intialize_cells which fills the cells array such
    such that the fraction of alive cells is approximately target_alive_fraction
    */
    fill_cells(cell, num_cells, target_alive_fraction);

    //Output time step, state of cells and fraction of alive cells
    //calls the function from the module output.h and output.cpp
    output_state(0, cell, num_cells);

    // Evolution loop starts here
    for (int t = 0; t < num_steps; t++) {
        // Updating cells and call the function update_cell_array from evolution.h and evolution.cpp
        update_cell_array(cell, num_cells);

       // Output time step, state of cells, and fraction of alive cells
        output_state(t + 1, cell, num_cells);
    }

    return 0;
}

