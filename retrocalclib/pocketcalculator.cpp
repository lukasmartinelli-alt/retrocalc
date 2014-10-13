#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

void pocketCalc(std::istream &in, std::ostream &out) {
	while (in) {
		std::string line { };
		if (getline(in, line)) {
			try {
				std::istringstream is { line };
				printLargeNumber(calc(is), out);
			} catch (std::overflow_error &e) {
				printError(std::cout);
			} catch (std::invalid_argument &e) {
				printError(std::cout);
			}
			in.clear();
			out.flush();
		}
	}
}

