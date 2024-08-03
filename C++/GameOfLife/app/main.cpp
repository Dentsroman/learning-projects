#include "GameOfLife.h"

int main() {
	try{ eat_popo(); }
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	std::cin.get();
	return EXIT_SUCCESS;
}