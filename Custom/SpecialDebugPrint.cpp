#include "SpecialDebugPrint.h"
#include <iostream>
#include <string>

//template<typename output>
void SpecialDebugPrint::print(std::string label, float value)
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

unsigned int SpecialDebugPrint::ticks = 0;
std::unordered_map<std::string, float> SpecialDebugPrint::storage;