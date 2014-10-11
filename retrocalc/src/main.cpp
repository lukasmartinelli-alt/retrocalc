#include <iostream>
#include "calc.h"
#include "sevensegment.h"

int main() {
	std::cout << "What can I calculate for you today, Sir?\n";
	int result = calc(std::cin);
	printNumber(std::cout, result);
	return 0;
}
