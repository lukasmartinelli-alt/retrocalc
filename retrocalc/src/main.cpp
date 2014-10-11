#include <iostream>
#include "calc.h"
#include "sevensegment.h"
#include <stdexcept>


int main() {
	std::cout << "What can I calculate for you today, Sir?\n";
	try {
		int result = calc(std::cin);
		printNumber(std::cout, result);
	} catch(std::overflow_error &e) {
		printError(std::cout);
	} catch(std::invalid_argument &e) {
		printError(std::cout);
	}
	return 0;
}
