#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "sevensegment.h"
#include "calc.h"
#include <vector>
#include <stdexcept>
#include <sstream>


void calcAddsNumbers() {
	//Act
	int result = calc(1, 2, '+');

	//Assert
	ASSERT_EQUAL(3, result);
}

void calcSubtractsSecondFromFirst() {
	//Act
	int result = calc(1, 2, '-');

	//Assert
	ASSERT_EQUAL(-1, result);
}

void calcDividesFirstWithSecond() {
	//Act
	int result = calc(5, 2, '/');

	//Assert
	ASSERT_EQUAL(2, result);
}

void calcMultipliesNumbers() {
	//Act
	int result = calc(5, 2, '*');

	//Assert
	ASSERT_EQUAL(10, result);
}

void calcThrowsInvalidArgExceptionForUnkownOperator() {
	//Act & Assert
	ASSERT_THROWS(calc(1, 2, '^'), std::invalid_argument);
}

void calcThrowsOverflowExceptionForDivisionByZero() {
	//Act & Assert
	ASSERT_THROWS(calc(1, 0, '/'), std::overflow_error);
}

void calcReadsReturnsResultForValidInput() {
	//Arrange
	std::istringstream in {"1 + 2"};

	//Act
	int result = calc(in);

	//Assert
	ASSERT_EQUAL(3, result);
}

void calcReadsThrowsExceptionForInvalidInput() {
	//Arrange
	std::istringstream in {"1 + +"};

	//Act & Assert
	ASSERT_THROWS(calc(in), std::exception);
}

void getDigitReturnsCorrectSegmentsForNumberZero() {
	//Act
	auto digit = getDigit(0);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL("   ",digit.at(2));
	ASSERT_EQUAL("| |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberOne() {
	//Act
	auto digit = getDigit(1);

	//Assert
	ASSERT_EQUAL("   ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL("   ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberTwo() {
	//Act
	auto digit = getDigit(2);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("|  ",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberThree() {
	//Act
	auto digit = getDigit(3);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberFour() {
	//Act
	auto digit = getDigit(4);

	//Assert
	ASSERT_EQUAL("   ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberFive() {
	//Act
	auto digit = getDigit(5);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("|  ",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberSix() {
	//Act
	auto digit = getDigit(6);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("|  ",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("| |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberSeven() {
	//Act
	auto digit = getDigit(7);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("  |",digit.at(1));
	ASSERT_EQUAL("   ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL("   ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberEight() {
	//Act
	auto digit = getDigit(8);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("| |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitReturnsCorrectSegmentsForNumberNine() {
	//Act
	auto digit = getDigit(9);

	//Assert
	ASSERT_EQUAL(" - ",digit.at(0));
	ASSERT_EQUAL("| |",digit.at(1));
	ASSERT_EQUAL(" - ",digit.at(2));
	ASSERT_EQUAL("  |",digit.at(3));
	ASSERT_EQUAL(" - ",digit.at(4));
}

void getDigitBiggerThanTenThrowsInvalidArgException() {
	//Act & Assert
	ASSERT_THROWS(getDigit(10), std::invalid_argument);
}


void printDigitsRendersMultipleDigits() {
	//Arrange
	std::vector<std::string> digitZero = {" - ",
									  "| |",
									  "   ",
									  "| |",
									  " - "};
	std::vector<std::string> digitNine = {" - ",
									  "| |",
									  " - ",
									  "  |",
									  "   "};

	std::vector<std::vector<std::string>> digits {digitZero, digitNine};
	std::ostringstream out {};

	//Act
	printDigits(out, digits, 5);

	//Assert
	std::string expected = {
		" -  - \n"
		"| || |\n"
		"    - \n"
		"| |  |\n"
		" -    \n"
	};
	ASSERT_EQUAL(expected, out.str());
}

void printNumberRendersMultipleDigits() {
	//Arrange
	std::ostringstream out {};
	unsigned int number { 319 };
	//Act
	printNumber(out, number);
	//Assert
	std::string expected = {
		" -     - \n"
		"  |  || |\n"
		" -     - \n"
		"  |  |  |\n"
		" -     - \n"
	};
	ASSERT_EQUAL(expected, out.str());
}

void printNumberCanPrintZero() {
	//Arrange
	std::ostringstream out {};
	unsigned int number { 0 };
	//Act
	printNumber(out, number);
	//Assert
	std::string expected = {
		" - \n"
		"| |\n"
		"   \n"
		"| |\n"
		" - \n"
	};
	ASSERT_EQUAL(expected, out.str());
}

void printNumberCanPrintNegativeNumbers() {
	//Arrange
	std::ostringstream out {};
	//Act
	printError(out);
	//Assert
	std::string expected = {
		" -             \n"
		"|              \n"
		" -  -  -  -  - \n"
		"|  |  |  | ||  \n"
		" -        -    \n"
	};
	ASSERT_EQUAL(expected, out.str());
}

void printErrorPrintsErrorSymbol() {
	//Arrange
	std::ostringstream out {};
	const int number { -1 };
	//Act
	printNumber(out, number);
	//Assert
	std::string expected = {
		"      \n"
		"     |\n"
		" -    \n"
		"     |\n"
		"      \n"
	};
	ASSERT_EQUAL(expected, out.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;

	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberZero));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberOne));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberTwo));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberThree));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberFour));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberFive));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberSix));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberSeven));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberEight));
	s.push_back(CUTE(getDigitReturnsCorrectSegmentsForNumberNine));
	s.push_back(CUTE(getDigitBiggerThanTenThrowsInvalidArgException));
	s.push_back(CUTE(printDigitsRendersMultipleDigits));
	s.push_back(CUTE(printNumberRendersMultipleDigits));

	s.push_back(CUTE(calcAddsNumbers));
	s.push_back(CUTE(calcSubtractsSecondFromFirst));
	s.push_back(CUTE(calcDividesFirstWithSecond));
	s.push_back(CUTE(calcMultipliesNumbers));
	s.push_back(CUTE(calcThrowsInvalidArgExceptionForUnkownOperator));
	s.push_back(CUTE(calcThrowsOverflowExceptionForDivisionByZero));
	s.push_back(CUTE(calcReadsReturnsResultForValidInput));
	s.push_back(CUTE(calcReadsThrowsExceptionForInvalidInput));
	s.push_back(CUTE(printNumberCanPrintZero));
	s.push_back(CUTE(printNumberCanPrintNegativeNumbers));
	s.push_back(CUTE(printErrorPrintsErrorSymbol));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



