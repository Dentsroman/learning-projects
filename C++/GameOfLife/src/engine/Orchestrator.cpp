// The ochestrator will handle interactions between all cells and the initial setup as it has the data of all of them. 
// It should see the cell positions, based on their coordenates all cells that have an adjacent cell next to them will THEN see if the color is different, 
// if its then it will run the die function or whichever is necessary

//Will contain the loop of functions the engine must do, like physics calculations, rendering and game logic functions
#include "Orchestrator.h"

Orchestrator::Orchestrator() : isRunning(false) {}

Orchestrator::~Orchestrator() = default;

Orchestrator& Orchestrator::getInstance() {
    static Orchestrator instance;
    return instance;
}

void Orchestrator::execute() {
    std::lock_guard<std::mutex> guard(lock);
    if (isRunning) {
        return;
    }
    isRunning = true;

    try {
        read_config();
		initial_setup(config);

        while (isRunning) {
            interactions();
            
        }
    }
    catch (...) {
        isRunning = false;
        throw;
    }

    isRunning = false;
}

Orchestrator::read_config() {
	//Reads the json file with the scenario
}

Orchestrator::initial_setup(std::string config) {
	//Creates the cells based on the json file
}

Orchestrator::get_cell_positions() {
	//Gets the positions of all cells
}

Orchestrator::check_adjacent_cells() {
	//Checks if there are adjacent cells
}