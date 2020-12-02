#include "QMsgClass2.h"

#include <iostream>

void QMsgClass2::sayHello(std::string name)
{
	std::string msg = "Hello " + name;
	std::cout << "QMsgClass2 Event: " << msg << std::endl;

	notifyAll(msg);
}
