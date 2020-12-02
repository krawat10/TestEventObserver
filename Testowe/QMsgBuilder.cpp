#include "QMsgBuilder.h"
#include "QMsgClass1.h"
#include "QMsgClass2.h"

std::unique_ptr<QMsg> QMsgBuilder::Build(std::string expr)
{
	auto params = GetParams(expr);
	
	if (const auto it = expr.rfind("QMsgClass1");it != std::string::npos && params.empty())
	{
		return std::make_unique<QMsgClass1>();
	}

	if (const auto it = expr.rfind("QMsgClass1"); it != std::string::npos && !params.empty())
	{
		return std::make_unique<QMsgClass1>(params[0]);
	}

	if (const auto it = expr.rfind("QMsgClass2"); it != std::string::npos)
	{
		return std::make_unique<QMsgClass2>();
	}
}

std::vector<std::string> QMsgBuilder::GetParams(std::string& str)
{
	std::vector<std::string> out;
	size_t start;
	size_t end = 0;
	auto delim = '|';

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}

	out.erase(out.begin());

	return out;
}
