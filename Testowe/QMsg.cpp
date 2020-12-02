#include "QMsg.h"

#include <iostream>

void QMsg::sayGoodBye()
{
	std::string msg = "Goodbye";
	std::cout << msg << std::endl;

	notifyAll(msg);
}
