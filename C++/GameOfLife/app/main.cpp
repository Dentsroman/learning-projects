//#include "Renderer.h"
//#include "Loop.h"
//#include "Orchestrator.h"
#include "GameOfLife.h"
#include <iostream>


int main() {
	//try {
	//	Loop::getInstance().execute();
	//	Orchestrator::getInstance().execute();
	//	Renderer& renderer = Renderer::getInstance(800, 600, "2D Grid");
	//	renderer.initialize();
	//	renderer.generateGrid(10, 1.0f); // 10 cells, grid size of 1.0
	//	renderer.run();
	//	return 0;
	//	}
	//}
	//catch (std::exception& e) {
	//	std::cout << "Exception: " << e.what() << std::endl;
	//	return EXIT_FAILURE;
	//}
	int value = eat_popo();
	std::cin.get();
	return EXIT_SUCCESS;
}