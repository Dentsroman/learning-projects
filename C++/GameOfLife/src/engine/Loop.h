#ifndef LOOP_H
#define LOOP_H
#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>

class Loop {
public:
    Loop(int32_t id, std::string type);

protected:
	// Main loop functions
    void start();
    void on_enable();
    void on_initialize();
    void fixed_update();
    void update(float deltaTime);
    void render();
    void on_disable();

private:
    // Utility functions for the main loop
    float GetDeltaTime();          // Calculates time between frames
    void SleepForFrameCap(int fps); // Optionally sleep to maintain a consistent frame rate

    // Time-keeping variables
    std::chrono::high_resolution_clock::time_point previousTime;
    float accumulator;
    const float fixedTimeStep;
};

#endif //LOOP_H