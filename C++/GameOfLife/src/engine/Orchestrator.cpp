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
        json config_json;
        read_config("scenario-1.json", config_json);
		std::cout << config_json.dump(4) << std::endl;
		initial_setup(config_json);

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

int Orchestrator::read_config(const std::string& config_path, json& config_json) {
    std::ifstream config_file(config_path);
    if (!config_file.is_open()) {
		std::cout << "Could not open config file" << std::endl;
		return EXIT_FAILURE;
    }

    config_file >> config_json;

    return EXIT_SUCCESS;
}

int Orchestrator::initial_setup(json config) {
	//Creates the cells based on the json file
	return EXIT_SUCCESS;
}

Orchestrator::get_cell_positions() {
	//Gets the positions of all cells
}

Orchestrator::check_adjacent_cells() {
	//Checks if there are adjacent cells
}

Orchestrator::interactions() {
	//Runs the interactions between cells
}