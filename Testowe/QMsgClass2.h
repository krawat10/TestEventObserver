#pragma once
#include <functional>
#include <string>


#include "Event.h"
#include "QMsg.h"

class QMsgClass2 : public QMsg
{
public:
	QMsgClass2() = default;

	void sayHello(std::string name);
};
