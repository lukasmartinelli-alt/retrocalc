#include "calc.h"
#include <istream>
#include <map>
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
	  default: throw std::invalid_argument("Operator is not supported");
	}
}

int calc(std::istream &in) {
	int value1{}, value2{};
	char operatorSymbol{};

	in >> value1;
	in >> value2;
	in >> operatorSymbol;

	return calc(value1, value2, operatorSymbol);
}

