#ifndef DIGIT_H_
#define DIGIT_H_

#include <vector>
#include <string>
#include <iosfwd>

std::vector<std::string> getDigit(unsigned int number);
std::vector<std::string> scaleDigit(std::vector<std::string> digit, unsigned int factor);
std::vector<std::string> scaleHorizontally(std::vector<std::string> digit, unsigned int factor);
std::vector<std::string> scaleVertically(std::vector<std::string> digit, unsigned int factor);
void printNumber(std::ostream &out, unsigned int number);
void printDigits(std::ostream &out, std::vector<std::vector<std::string>> printableDigits, unsigned int lineCount, std::string margin);

#endif /* DIGIT_H_ */
