#include "sevensegment.h"
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <ostream>

Digit getDigit(unsigned int number) {
	if(number > 9) throw std::invalid_argument("Only digits from 0 to 9 are supported");

	Digit digit {};

	for(auto const line: DIGITS) {
		digit.push_back(line.at(number));
	}

	return digit;
}

Digit scaleHorizontally(Digit digit, unsigned int factor) {
	for(auto &line: digit) {
		const unsigned int middle = line.size() / 2;
		const char scalingCharacter = line.at(middle);
		line.insert(middle, factor-1, scalingCharacter);
	}
	return digit;
}

Digit scaleVertically(Digit digit, unsigned int factor) {
	Digit scaledDigit{};

	for(auto it=digit.begin(); it != digit.end(); ++it) {
		const auto index = std::distance(digit.begin(), it);

		scaledDigit.push_back(*it);
		if(index % 2 == 1) {
			scaledDigit.push_back(*it);
		}
	}
	return scaledDigit;
}

Digit scaleDigit(Digit digit, unsigned int factor) {
	return scaleVertically(scaleHorizontally(digit, factor), factor);
}

void printDigits(std::ostream &out, std::vector<Digit> printableDigits, unsigned int lineCount, std::string margin) {
	Digit lines(lineCount);

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


void printNumber(std::ostream &out, int number) {
	std::vector<Digit> printableDigits {};
	unsigned int positiveNumber { number < 0 ? -number : number };

	do {
		const unsigned int digit { positiveNumber % 10 };
		printableDigits.insert(printableDigits.begin(), getDigit(digit));
		positiveNumber /= 10;
	} while (positiveNumber > 0);

	if(number < 0) {
		printableDigits.insert(printableDigits.begin(), MINUS_SYMBOL);
	}

	printDigits(out, printableDigits, 5, "");
}
