#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>
#include <mutex>
#include <nlohmann/json.hpp>

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

	json config_json;
	int read_config(const std::string& config_path, json& config_json);

	void initial_setup(json config_json);
	void get_cell_positions();
	void check_adjacent_cells();
};

#endif //ORCHESTRATOR_H