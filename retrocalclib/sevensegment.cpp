#include "sevensegment.h"
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <ostream>

static const std::vector<Digit> DIGITS = {{" - ", "| |", "   ", "| |", " - "},
										  {"   ", "  |", "   ", "  |", "   "},
										  {" - ", "  |", " - ", "|  ", " - "},
										  {" - ", "  |", " - ", "  |", " - "},
										  {"   ", "| |", " - ", "  |", "   "},
										  {" - ", "|  ", " - ", "  |", " - "},
										  {" - ", "|  ", " - ", "| |", " - "},
										  {" - ", "  |", "   ", "  |", "   "},
										  {" - ", "| |", " - ", "| |", " - "},
										  {" - ", "| |", " - ", "  |", " - "}};

static const Digit MINUS_SYMBOL = {"   ", "   ", " - ", "   ", "   "};

static const std::vector<Digit> ERROR_DIGITS = {{" - ", "|  ", " - ", "|  ", " - "},
												{"   ", "   ", " - ", "|  ", "   "},
												{"   ", "   ", " - ", "|  ", "   "},
												{"   ", "   ", " - ", "| |", " - "},
												{"   ", "   ", " - ", "|  ", "   "}};

Digit getDigit(unsigned int number) {
	if(number > 9) throw std::invalid_argument("Only digits from 0 to 9 are supported");
	return DIGITS.at(number);
}

void printDigits(std::ostream &out, std::vector<Digit> printableDigits, unsigned int lineCount) {
	Digit lines(lineCount);

	for(const auto digit : printableDigits) {
		for (auto it = digit.begin(); it != digit.end(); ++it) {
			auto index = std::distance(digit.begin(), it);
			lines.at(index).append(*it);
		}
	}

	for(auto line : lines) {
		out << line << "\n";
	}
}

void printLargeNumber(int number, std::ostream &out) {
	std::vector<Digit> printableDigits {};
	unsigned int positiveNumber { number < 0 ? -number : number };

	if(number < 0) {
		printableDigits.push_back(MINUS_SYMBOL);
	}

	std::string numberString{std::to_string(positiveNumber)};
	for(const auto asciiCode : numberString) {
		const unsigned int digit {asciiCode - '0'};
		printableDigits.push_back(getDigit(digit));
	}

	printDigits(out, printableDigits, 5);
}

void printError(std::ostream &out) {
	printDigits(out, ERROR_DIGITS, 5);
}
