#pragma once

#include "Types/DefaultCommand.h"

#include <vector>
#include <string>

class GraphEncodersCommand : public DefaultCommand {

public:
	GraphEncodersCommand();
	void Execute() override;

protected:
	std::vector<std::string> m_labels;
};