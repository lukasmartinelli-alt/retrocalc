#ifndef DIGIT_H_
#define DIGIT_H_

#include <vector>
#include <string>

std::vector<std::string> getDigit(unsigned int number);
std::vector<std::string> scaleDigit(std::vector<std::string> digit, unsigned int factor);
std::vector<std::string> scaleHorizontally(std::vector<std::string> digit, unsigned int factor);
std::vector<std::string> scaleVertically(std::vector<std::string> digit, unsigned int factor);

#endif /* DIGIT_H_ */
