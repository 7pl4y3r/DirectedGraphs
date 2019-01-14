#include <iostream>

#include "staticGraph.h"
#include "utils.h"

void showMainMenu();
void chooseMain();
void showProblemMenu();
void chooseProblem1();
void chooseProblem2();

void showMainMenu()
{
	std::cout << "1 - static (using matrixes)\n";
	std::cout << "2 - dynamic\n";
}

void chooseMain()
{

	char option;
	do {
	
	std::cout << "Allocation type.. ";
	std::cin >> option;

	switch (option) {
	
		case '1': chooseProblem1(); break;
		case '2': chooseProblem2(); break;
	
	}
	
	} while (option != 'e');
}

void showProblemMenu()
{
	std::cout << "1 - get all degrees\n";
}

void chooseProblem1()
{
	showProblemMenu();
	
	char option;
	int n, m[6][6];

	Utils::readMatrixFromFile(m, n);
	do {
	
		std::cout << "problem id.. ";
		std::cin >> option;

		switch (option) {
		
			case '1': StaticGraph::printDegrees(m, n); break;
		
		}
	
	} while (option != 'e');

}

void chooseProblem2()
{
	std::cout << "Coming in the future\n";
}

int main()
{
	showMainMenu();
	chooseMain();


return 0;
}
