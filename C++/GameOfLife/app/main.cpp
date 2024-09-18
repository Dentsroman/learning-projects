#include "GameOfLife.h"

int main() {
	try {
		Loop::getInstance().execute();
		Orchestrator::getInstance().execute();
		return 0;
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	std::cin.get();
	return EXIT_SUCCESS;
}