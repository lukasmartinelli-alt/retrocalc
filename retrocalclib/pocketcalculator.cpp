#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"
#include <stdexcept>
#include <sstream>

void pocketCalc(std::istream &in, std::ostream &out) {
	std::string line {};
	while (std::getline(in, line)) {
		try {
			std::istringstream is { line };
			printLargeNumber(calc(is), out);
		} catch (std::exception const &) {
			printError(out);
		}
		out.flush();
	}
}

