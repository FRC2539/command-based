#ifndef NETCONSOLE_H
#define NETCONSOLE_H

#include <unordered_map>
#include <string>

class Netconsole
{
public:
	// Templated methods need to be implemented in the header file, otherwise
	// there will be a linker error.
	template<typename printable>
	static void print(std::string label,  printable value)
	{
		sendToConsole(label, std::to_string(value));
	};
	template<typename printable>
	static void instant(std::string label,  printable value)
	{
		writeOut(label, std::to_string(value));
	};
	static void reset();

protected:
	static void sendToConsole(std::string label, std::string value);
	static void writeOut(std::string label, std::string value);

	static std::unordered_map<std::string, std::string> storage;
	static unsigned int ticks;
};

#endif

