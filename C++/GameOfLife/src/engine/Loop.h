#ifndef LOOP_H
#define LOOP_H

#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>
#include <mutex>

class Loop {
public:
    static Loop& getInstance();
    void execute();

protected:
	// Main loop functions
	void spawn();
    void move();

private:
    // Utility functions for the main loop
    Loop();
    ~Loop();
    Loop(const Loop&) = delete;
    Loop& operator=(const Loop&) = delete;
    bool isRunning;
    std::mutex lock;

    float get_delta_time();          // Calculates time between frames
    void sleep_for_frame_cap(int fps); // Optionally sleep to maintain a consistent frame rate

    // Time-keeping variables
    std::chrono::high_resolution_clock::time_point previousTime;
    float accumulator;
    const float fixedTimeStep;
};

#endif //LOOP_H