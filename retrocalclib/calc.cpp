#include "calc.h"
#include <istream>
#include <map>
#include <stdexcept>

int calc(int val1, int val2, char op) {
	switch (op)
	{
	  case '+': return val1 + val2;
	  case '-': return val1 - val2;
	  case '/':
		  if(val2 == 0) throw std::overflow_error("Division by zero is not allowed");
		  return val1 / val2;
	  case '*': return val1 * val2;
	  default: throw std::invalid_argument("Operator is not supported");
	}
}

int calc(std::istream &in) {
	int val1{}, val2{};
	char op{};

	in >> val1;
	in >> val2;
	in >> op;

	return calc(val1, val2, op);
}

