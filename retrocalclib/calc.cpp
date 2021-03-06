#include "calc.h"
#include <istream>
#include <stdexcept>

int calc(int value1, int value2, char operatorSymbol) {
	switch (operatorSymbol)
	{
	  case '+': return value1 + value2;
	  case '-': return value1 - value2;
	  case '/':
		  if(value2 == 0) throw std::overflow_error("Division by zero is not allowed");
		  return value1 / value2;
	  case '*': return value1 * value2;
	  case '%': return value1 % value2;
	  default: throw std::invalid_argument("Operator is not supported");
	}
}

int calc(std::istream &in) {
	int value1{}, value2{};
	char operatorSymbol{};

	in >> value1 >> operatorSymbol >> value2;

	if(in.fail()) {
		in.clear();
		throw std::overflow_error("Input does not have correct format");
	}

	return calc(value1, value2, operatorSymbol);
}

