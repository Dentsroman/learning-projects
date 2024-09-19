//Will contain the loop of functions the engine must do, like physics calculations and game logic functions
//Orchestrator functions will be called by the Loop class
#include "Loop.h"

Loop::Loop() : isRunning(false) {}

Loop::~Loop() = default;

Loop& Loop::getInstance() {
    static Loop instance;
    return instance;
}

void Loop::execute() {
    std::lock_guard<std::mutex> guard(lock);
    if (isRunning) {
        return;
    }
    isRunning = true;

    try {
        while (isRunning) {
			spawn();
			move();
			sleep_for_frame_cap(60);
        }
    }
    catch (...) {
        isRunning = false;
        throw;
    }

    isRunning = false;
}

Loop::get_delta_time() {

    const float fixedDeltaTime = 1.0f / 60.0f; // Fixed delta time for 60 FPS
    auto previousTime = std::chrono::high_resolution_clock::now();
    float accumulatedTime = 0.0f;


}

Loop::spawn() {

}

Loop::move() {

}

Loop::sleep_for_frame_cap(int fps) {

}