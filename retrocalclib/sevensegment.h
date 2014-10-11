#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include <vector>
#include <string>
#include <iosfwd>

typedef std::vector<std::string> Digit;

/**
 * Each vector contains one printable line with all the numbers from 0 to 9
 * in seven segment format.
 */
static const std::vector<std::vector<std::string>> DIGITS = {{" - ", "   ", " - ", " - ", "   ", " - ", " - ", " - ", " - ", " - "},
															 {"| |", "  |", "  |", "  |", "| |", "|  ", "|  ", "  |", "| |", "| |"},
															 {"   ", "   ", " - ", " - ", " - ", " - ", " - ", "   ", " - ", " - "},
														     {"| |", "  |", "|  ", "  |", "  |", "  |", "| |", "  |", "| |", "  |"},
															 {" - ", "   ", " - ", " - ", "   ", " - ", " - ", "   ", " ̣̣- ", "   "}};

static const Digit MINUS_SYMBOL = {"   ",
 	 	 	 	 	 	 	 	   "   ",
								   " - ",
								   "   ",
                                   "   "};

static const Digit ERROR_SYMBOL = {" - ",
 	 	 	 	 	 	 	 	   "|  ",
								   " - ",
								   "|  ",
                                   " - "};


/**
 * Extract the digit for the given number
 * @param number A number from 0 to 9
 * @return The digit that corresponds to the number
 */
Digit getDigit(unsigned int number);
/**
 * Scale a digit horizontally and vertically by a given factor
 * @param digit to scale
 * @param factor The factor used for scaling (>1)
 */
Digit scaleDigit(Digit digit, unsigned int factor);
/**
 * Scale a digit horizontally by a given factor
 * @param digit The digit to scale
 * @param factor The factor used for scaling (>1)
 */
Digit scaleHorizontally(Digit digit, unsigned int factor);
/**
 * Scale a digit vertically by a given factor
 * @param digit The digit to scale
 * @param factor The factor used for scaling (>1)
 */
Digit scaleVertically(Digit digit, unsigned int factor);
/**
 * Print digits for a given number to the output stream.
 * @param out The output stream to print the digits to
 * @param number The number to display
 */
void printNumber(std::ostream &out, int number);
/**
 * Print given digits to an output stream.
 * If the number is negative it will be prefixed with a minus symbol.
 * If the digits are scaled vertically you have to provide the correct lineCount.
 * @param out The output stream to print the digits to
 * @param printableDigits The digits to print
 * @param lineCount How many line one digit contains
 * @param margin The margin between different digits
 */
void printDigits(std::ostream &out, std::vector<Digit> printableDigits, unsigned int lineCount, std::string margin);

#endif
