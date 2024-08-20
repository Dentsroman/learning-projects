//Will contain the loop of functions the engine must do, like physics calculations, rendering and game logic functions
#include "Loop.h"

Loop::Loop() :
    previousTime(std::chrono::high_resolution_clock::now()),  // Initialize previousTime to the current time
    accumulator(0.0f),                                        // Accumulator starts at 0
    fixedTimeStep(1.0f / 60.0f)                               // Set a fixed time step, e.g., 60 FPS (fixed update)
{
    // Initialization or debug messages if needed
    std::cout << "GameEngine initialized with a fixed timestep of " << fixedTimeStep << " seconds." << std::endl;
}

Loop::start(){

}

Loop::on_enable() {

}

Loop::on_initialize() {

}

Loop::fixed_update() {

}

Loop::update(float deltaTime) {

}

Loop::render() {

}

Loop::on_disable() {

}