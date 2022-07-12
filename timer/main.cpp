#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <thread>
#include <string>

#ifdef _WIN32 || _WIN64
const char* clearMsg = "cls";
#endif

#ifdef __unix__
const char* clearMsg = "clear";
#endif


class Timer
{
private:
	bool stopFlag = false;
	struct tm* u = nullptr;
	time_t t = 0;
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
			system(clearMsg);
			std::string timeStr = "";
			timeStr += std::to_string(u->tm_hour) + ":" + std::to_string(u->tm_min) + ":" + std::to_string(u->tm_sec);
			std::cout << timeStr;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			t--;
			u = gmtime(&t);
		}

		system(clearMsg);
		std::cout << "Time is over\n" << "Write stop and press Enter to stop notify\n";

		//create threads
		std::thread t(&Timer::notify, this);
		std::thread t1(&Timer::stopNotify, this);
		t.join();
		t1.join();
	}

	// notify about end of time
	void notify()
	{
		while (!stopFlag)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "\a";
		}
	}

	void stopNotify()
	{
		std::string str;
		while (str != "stop")
		{
			std::cin >> str;
		}
		stopFlag = true;
		system("cls");
		run();
	}
};


int main()
{
	Timer timer;
	timer.run();
	return 0;
}