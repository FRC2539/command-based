#include "Netconsole.h"

#include <iostream>

void Netconsole::print(std::string label, std::string value)
{
	sendToConsole(label, value);
}

void Netconsole::instant(std::string label, std::string value)
{
	writeOut(label, value);
}

void Netconsole::sendToConsole(std::string label, std::string value)
{
	if (storage.count(label) == 0)
	{
		writeOut(label, value);
	}

	storage[label] = value;
	ticks++;

	if (ticks % (50 * storage.size()) == 0)
	{
		for (auto element : storage)
		{
			writeOut(element.first, element.second);
		}
	}
}

void Netconsole::writeOut(std::string label, std::string value)
{
	std::cout << label << ": " << value << std::endl;
}

void Netconsole::reset()
{
	storage.clear();
}

unsigned int Netconsole::ticks = 0;
std::unordered_map<std::string, std::string> Netconsole::storage;
