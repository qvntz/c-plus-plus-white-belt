#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int q;
	std::cin >> q;
	std::vector<bool> is_nervous;

	for (int i = 0; i < q; ++i) {
		std::string operation_code;
		std::cin >> operation_code;

		if (operation_code == "WORRY_COUNT") {
			std::cout << count(begin(is_nervous), end(is_nervous), true) << "\n";
		}
		else {
			if (operation_code == "WORRY" || operation_code == "QUIET") {
				int person_index;
				std::cin >> person_index;
				
				is_nervous[person_index] = (operation_code == "WORRY");
			}
			else if (operation_code == "COME") {
				int person_count;
				std::cin >> person_count;
				is_nervous.resize(is_nervous.size() + person_count, false);
			}
		}
	}

	return 0;
}
