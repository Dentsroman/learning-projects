#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <memory>
#include <chrono>
#include <cstdint>

class Cell {
public:
    Cell(int id, std::string type);
	~Cell();

    void initialize();
    void update();
    void render();

private:
    // Member variables
    uint64_t __cell_id;
    uint32_t __loc_in_grid[2];
    int16_t __life_points;


    // Private helper functions
    int countNeighbors(int x, int y);
};

#endif //CELL_H