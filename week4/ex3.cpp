#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	std::string line;
	while (getline(input, line)) {
		std::cout << line << "\n";
		output << line << "\n";
	}

	return 0;
}
