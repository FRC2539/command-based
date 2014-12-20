#ifndef SPECIAL_DEBUG_PRINT_H
#define SPECIAL_DEBUG_PRINT_H

#include <unordered_map>

class SpecialDebugPrint
{
public:
	//template<typename output>
	static void print(std::string label, float value);

protected:
	static std::unordered_map<std::string, float> storage;
	static unsigned int ticks;
};

#endif 

