#pragma once
#include <optional>
#include <string>

#include "QMsg.h"
#include "QMsgClass1.h"

class QMsgBuilder
{
public:
	QMsgBuilder() = default;

	std::unique_ptr<QMsg> Build(std::string expr);
	std::vector<std::string> GetParams(std::string& str);
};


