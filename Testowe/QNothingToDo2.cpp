#include "QNothingToDo2.h"

#include <iostream>

void QNothingToDo2::OnQMsgClass2(std::string msg)
{
	std::cout << "QNothingToDo2 - Event received, msg: " << msg << std::endl;
}
