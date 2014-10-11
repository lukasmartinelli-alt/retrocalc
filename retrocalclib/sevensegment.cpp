#include "sevensegment.h"
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <ostream>

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

void printDigits(std::ostream &out, std::vector<std::vector<std::string>> printableDigits, unsigned int lineCount, std::string margin) {
	std::vector<std::string> lines(lineCount);

	for(const auto digit : printableDigits) {
		for (auto it = digit.begin(); it != digit.end(); ++it) {
			auto index = std::distance(digit.begin(), it);
			lines.at(index).append(margin);
			lines.at(index).append(*it);
		}
	}

	for(auto line : lines) {
		out << line << "\n";
	}
}

void printNumber(std::ostream &out, unsigned int number) {
	std::vector<std::vector<std::string>> printableDigits {};

	do {
		const unsigned int digit { number % 10 };
		printableDigits.insert(printableDigits.begin(), getDigit(digit));
		number /= 10;
	} while (number > 0);

	printDigits(out, printableDigits, 5, "");
}
