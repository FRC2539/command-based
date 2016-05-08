#pragma once

#include "Types/DefaultCommand.h"

#include <vector>
#include <string>

class GraphEncodersCommand : public DefaultCommand {

public:
	GraphEncodersCommand();
	void Initialize() override;
	void Execute() override;
	void End() override;

protected:
	std::vector<std::string> m_labels;
};