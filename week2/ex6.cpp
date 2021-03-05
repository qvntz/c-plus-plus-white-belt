#include <iostream>
#include <string>
#include <vector>

const std::vector<int> MONTH_LENGTHS =
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main() {
	int q;
	std::cin >> q;

	int month = 0;

	std::vector<std::vector<std::string>> days_concerns(MONTH_LENGTHS[month]);

	for (int i = 0; i < q; ++i) {
		std::string operation_code;
		std::cin >> operation_code;

		if (operation_code == "ADD") {
			int day;
			std::string concern;
			std::cin >> day >> concern;
			--day;
			days_concerns[day].push_back(concern);
		}
		else if (operation_code == "NEXT") {
			const int old_month_length = MONTH_LENGTHS[month];
			month = (month + 1) % MONTH_COUNT;

			const int new_month_length = MONTH_LENGTHS[month];
			if (new_month_length < old_month_length) {
				std::vector<std::string> &last_day_concerns = days_concerns[new_month_length - 1];
				for (int day = new_month_length; day < old_month_length; ++day) {
					last_day_concerns.insert(
						end(last_day_concerns),
						begin(days_concerns[day]), end(days_concerns[day]));
				}
			}
			days_concerns.resize(new_month_length);
		}
		else if (operation_code == "DUMP") {
			int day;
			std::cin >> day;
			--day;
			
			std::cout << days_concerns[day].size() << " ";
			for (const std::string &concern : days_concerns[day]) {
				std::cout << concern << " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
