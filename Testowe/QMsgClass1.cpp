#include "QMsgClass1.h"


#include <functional>
#include <iostream>
#include <utility>

QMsgClass1::QMsgClass1(std::string name)
	:name_(std::move(name))
{
	
}

void QMsgClass1::sayHello()
{
	std::string msg = "Hello " + this->name_;
	std::cout << "QMsgClass1 Event: " << msg << std::endl;

	notifyAll(msg);
}
