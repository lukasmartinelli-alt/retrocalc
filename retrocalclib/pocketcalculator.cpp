#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"
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
				printError(out);
			} catch (std::invalid_argument &e) {
				printError(out);
			}
			out.flush();
		}
	}
}

