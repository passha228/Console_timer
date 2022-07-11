#include <iostream>
#include <ctime>



int main()
{
	size_t lastTime = time(NULL);
	std::cout << lastTime;
	while (true)
	{
		if (time(NULL) - lastTime > 1)
		{
			lastTime = time(NULL);
			std::cout << "\a";
		}
	}
	return 0;
}