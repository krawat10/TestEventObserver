#pragma once
#include <functional>
#include <string>
#include <vector>


#include "Event.h"
#include "QMsg.h"



class QMsgClass1 : public QMsg
{
public:
	QMsgClass1(std::string name = "User");
    void sayHello();

private:
	std::string name_;
};


