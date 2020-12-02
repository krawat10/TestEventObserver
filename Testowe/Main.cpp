// Testowe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "QMsgBuilder.h"
#include "QMsgClass2.h"
#include "QNothingToDo1.h"
#include "QNothingToDo2.h"

int main()
{
	auto* nothing1 = new QNothingToDo1();
	auto* nothing2 = new QNothingToDo2();

	auto builder = QMsgBuilder();
	auto class1 = builder.Build("QMsgClass1|paramName");
	auto class2 = builder.Build("QMsgClass2");

	if (class1 && class2)
	{
		// Subscribe
		class1->add([nothing1](const std::string s) { nothing1->OnQMsgClass1.push_back(s); });
		class1->add([nothing2](const std::string s) { nothing2->OnQMsgClass1.push_back(s); });
		
		// Should be added to OnQMsgClass1
		class1->sayGoodBye();
		dynamic_cast<QMsgClass1*>(class1.get())->sayHello();

		// Subscribe nothing2 (other style)
		class2->add(std::bind(&QNothingToDo2::OnQMsgClass2, nothing2, std::placeholders::_1));
		

		// Should trigger OnQMsgClass2 (cout)
		dynamic_cast<QMsgClass2*>(class2.get())->sayHello("some user");
	}


	for (auto nothing1_class1 : nothing1->OnQMsgClass1)
	{
		std::cout << "nothing1.OnQMsgClass1:" << nothing1_class1 << std::endl;
	}
	
	for (auto nothing2_class1 : nothing2->OnQMsgClass1)
	{
		std::cout << "nothing2.OnQMsgClass1:"  << nothing2_class1 << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
