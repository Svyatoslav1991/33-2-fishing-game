#include <iostream>
#include <vector>
#include <random>
#include "functions.h"

int main() {
	std::cout << "\tTASK 33.2 FISHING GAME\n\n";

	std::srand(std::time(NULL));
	int64_t level;
	do
	{
		std::cout << "Choose level (1 - 5):\n";
		std::cout << "1 - easy, 2 - adventurous, 3 - heroic, 4 - epic, 5 - Legendary\n";
		level = myCin<int64_t>();
	} while (level < 1 || level > 5);


	std::vector<int64_t> subjects (4, 0);
	const int64_t N = 9;
	

	int64_t count = 1;
	int64_t sector;

	try
	{
		while (true)
		{
			std::cout << "\nAttemp number " << count << "\n";

			for (int64_t i = 0; i < subjects.size(); )
			{
				subjects[i] = rand() % 9;
				bool isNew = true;
				for (int64_t j = i - 1; j >= 0; --j)
				{
					if (subjects[i] == subjects[j])
					{
						isNew = false;
						break;
					}
				}

				if (isNew)
				{
					++i;
				}
			}

			switch (level)
			{
			case 1:
			{
				std::cout << "The fish is in sector " << subjects[0] << "\n";
				std::cout << "Boots in sectors " << subjects[1] << ", " << subjects[2] << ", " << subjects[3] << "\n";
			}
			break;
			case 2:
				std::cout << "Boots in sectors " << subjects[1] << ", " << subjects[2] << ", " << subjects[3] << "\n";
				break;
			case 3:
				std::cout << "Boots in sectors " << subjects[1] << ", " << subjects[2] << ", UNKNOWN\n";
				break;
			case 4:
				std::cout << "Boots in sectors " << subjects[1] << ", UNKNOWN, UNKNOWN\n";
				break;
			default:
				break;
			}


			do
			{
				std::cout << "Enter the sector number to cast the fishing rod (0-8)\n";
				sector = myCin<int64_t>();
			} while (sector < 0 || sector > 8);

			if (sector == subjects[0])
			{
				throw count;
			}

			for (int64_t i = 1; i < subjects.size(); ++i)
			{
				if (sector == subjects[i])
				{
					throw static_cast<int64_t>(-1);
				}
			}

			std::cout << "You didn't catch anything, try again\n";

			count++;
		}
	}
	catch (int64_t value)
	{
		if (value > 0)
		{
			std::cout << "Congratulations! You caught a fish in " << count << " attempts\n";
		}
		else
		{
			std::cout << "Oops! You caught a boot. Game over!\n";
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << "Error: " << ex.what() << "\n";
	}
	catch ( ... )
	{
		std::cout << "Something went wrong...\n";
	}


	return 0;
}