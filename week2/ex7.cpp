#include <iostream>
#include <string>
#include <map>
#include <vector>

void PrintBusesForStop(std::map<std::string, std::vector<std::string>> &stops_to_buses,
					   const std::string &stop) {
	if (stops_to_buses.count(stop) == 0) {
		std::cout << "No stop\n";
	}
	else {
		for (const std::string &bus : stops_to_buses[stop]) {
			std::cout << bus << " ";
		}
		std::cout << "\n";
	}
}

void PrintStopsForBus(std::map<std::string, std::vector<std::string>> &buses_to_stops,
					  std::map<std::string, std::vector<std::string>> &stops_to_buses,
					  const std::string &bus) {
	if (buses_to_stops.count(bus) == 0) {
		std::cout << "No bus\n";
	}
	else {
		for (const std::string &stop : buses_to_stops[bus]) {
			std::cout << "Stop " << stop << ": ";

			if (stops_to_buses[stop].size() == 1) {
				std::cout << "no interchange";
			}
			else {
				for (const std::string &other_bus : stops_to_buses[stop]) {
					if (bus != other_bus) {
						std::cout << other_bus << " ";
					}
				}
			}
			std::cout << "\n";
		}
	}
}

void PrintAllBuses(const std::map<std::string, std::vector<std::string>> &buses_to_stops) {
	if (buses_to_stops.empty()) {
		std::cout << "No buses\n";
	}
	else {
		for (const auto &bus_item : buses_to_stops) {
			std::cout << "Bus " << bus_item.first << ": ";
			for (const std::string &stop : bus_item.second) {
				std::cout << stop << " ";
			}
			std::cout << "\n";
		}
	}
}

int main() {
	int q;
	std::cin >> q;

	std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;

	for (int i = 0; i < q; ++i) {
		std::string operation_code;
		std::cin >> operation_code;

		if (operation_code == "NEW_BUS") {
			std::string bus;
			std::cin >> bus;
			int stop_count;
			std::cin >> stop_count;
			
			std::vector<std::string> &stops = buses_to_stops[bus];
			stops.resize(stop_count);

			for (std::string &stop : stops) {
				std::cin >> stop;
				stops_to_buses[stop].push_back(bus);
			}
		}
		else if (operation_code == "BUSES_FOR_STOP") {
			std::string stop;
			std::cin >> stop;
			PrintBusesForStop(stops_to_buses, stop);
		}
		else if (operation_code == "STOPS_FOR_BUS") {
			std::string bus;
			std::cin >> bus;
			PrintStopsForBus(buses_to_stops, stops_to_buses, bus);
		}
		else if (operation_code == "ALL_BUSES") {

			PrintAllBuses(buses_to_stops);
		}
	}
	return 0;
}
