#include "digit.h"
#include <iterator>
#include <stdexcept>

const std::vector<std::vector<std::string>> DIGITS = {{" - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - "},
													  {"| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |"},
 													  {"   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - "},
   													  {"| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |"},
 													  {" - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " ̣̣- ", "   "}};

std::vector<std::string> getDigit(unsigned int number) {
	if(number > 9) throw std::invalid_argument("Only digits from 0 to 9 are supported");

	std::vector<std::string> digit {};

	for(auto const v: DIGITS) {
		digit.push_back(v.at(number));
	}

	return digit;
}
