#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include <vector>
#include <string>
#include <iosfwd>

using Digit = std::vector<std::string>;

/**
 * Extract the digit for the given number
 * @param number A number from 0 to 9
 * @return The digit that corresponds to the number
 */
Digit getDigit(unsigned int number);
/**
 * Print digits for a given number to the output stream.
 * @param out The output stream to print the digits to
 * @param number The number to display
 */
void printLargeNumber(int number, std::ostream &out);
/**
 * Print given digits to an output stream.
 * If the number is negative it will be prefixed with a minus symbol.
 * If the digits are scaled vertically you have to provide the correct lineCount.
 * @param out The output stream to print the digits to
 * @param printableDigits The digits to print
 * @param lineCount How many line one digit contains
 */
void printDigits(std::ostream &out, std::vector<Digit> printableDigits, unsigned int lineCount);
/**
 * Print error symbols to output stream
 * @param out The output stream to print the error to
 */
void printError(std::ostream &out);

#endif
