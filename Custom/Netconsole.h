#ifndef NETCONSOLE_H
#define NETCONSOLE_H

#include <unordered_map>

class Netconsole
{
public:
	//template<typename output>
	static void print(std::string label, float value);

protected:
	static std::unordered_map<std::string, float> storage;
	static unsigned int ticks;
};

#endif

