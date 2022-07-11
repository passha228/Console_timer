#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <thread>
#include <string>

class Timer
{
private:
	bool stopFlag = false;
	struct tm* u;
	time_t t;
public:

	void run()
	{
		std::cout << "write timers time:\n";
		std::cout << "hours: ";
		std::string h;
		std::cin >> h;

		std::cout << "minutes: ";
		std::string m;
		std::cin >> m;

		std::cout << "seconds: ";
		std::string s;
		std::cin >> s;

		t = std::atoi(h.c_str()) * 3600 + std::atoi(m.c_str()) * 60 + std::atoi(s.c_str());
		u = gmtime(&t);
		counter();
	}

	void counter()
	{
		while (t > 0)
		{
			system("cls");
			std::string timeStr = "";
			timeStr += std::to_string(u->tm_hour) + ":" + std::to_string(u->tm_min) + ":" + std::to_string(u->tm_sec);
			std::cout << timeStr;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			t--;
			u = gmtime(&t);
		}
	}

	// notify about end of time
	void notify()
	{
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "\a";
		}
	}

	void stopNotify()
	{
		char c = getchar();
		if (c == '\n')
			stopFlag = true;
	}
};







int main()
{
	Timer timer;
	timer.run();
	return 0;
}