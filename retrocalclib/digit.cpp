#include "digit.h"
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>

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

std::vector<std::string> scaleHorizontally(std::vector<std::string> digit, unsigned int factor) {
	for(auto &line: digit) {
		const unsigned int middle = line.size() / 2;
		const char scalingCharacter = line.at(middle);
		line.insert(middle, factor-1, scalingCharacter);
	}
	return digit;
}

std::vector<std::string> scaleVertically(std::vector<std::string> digit, unsigned int factor) {
	std::vector<std::string> scaledDigit{};

	for(auto it=digit.begin(); it != digit.end(); ++it) {
		auto index = std::distance(digit.begin(), it);

		scaledDigit.push_back(*it);
		if(index % 2 == 1) {
			scaledDigit.push_back(*it);
		}
	}
	return scaledDigit;
}

std::vector<std::string> scaleDigit(std::vector<std::string> digit, unsigned int factor) {
	return scaleVertically(scaleHorizontally(digit, factor), factor);
}
