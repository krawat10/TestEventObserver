#pragma once
#include <functional>
#include <string>

#include "Event.h"

class QMsg: public Event<std::function<void(std::string msg)>>
{
public:
	virtual ~QMsg() {}
	void sayGoodBye();
};
