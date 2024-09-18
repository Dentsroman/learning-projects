#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>
#include <mutex>

class Orchestrator {
public:
	static Orchestrator& getInstance();
	void execute();

protected:
	// Main loop functions

	void interactions();
private:
	Orchestrator();
	~Orchestrator();
	Orchestrator(const Orchestrator&) = delete;
	Orchestrator& operator=(const Orchestrator&) = delete;
	bool isRunning;
	std::mutex lock;

	std::string config;
	std::string read_config(const std::string& config_path);

	void initial_setup(std::string config);
	void get_cell_positions();
	void check_adjacent_cells();
};

#endif //ORCHESTRATOR_H