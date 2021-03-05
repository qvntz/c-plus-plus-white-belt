#include <exception>
#include <system_error>

class TimeServer {
public:
	std::string GetCurrentTime() {
		try {
			last_fetched_time = AskTimeServer();
		}
		catch (const std::system_error &) {
		}
		return last_fetched_time;
	}

private:
	std::string last_fetched_time = "00:00:00";
};
