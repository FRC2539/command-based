#include "Netconsole.h"

#include <iostream>

void Netconsole::sendToConsole(std::string label, std::string value)
{
	storage[label] = value;
	ticks++;

	if (ticks % (50 * storage.size()) == 0)
	{
		for (auto element : storage)
		{
			std::cout << element.first << ": " << element.second << "\n";
		}
	}
}

unsigned int Netconsole::ticks = 0;
std::unordered_map<std::string, std::string> Netconsole::storage;
