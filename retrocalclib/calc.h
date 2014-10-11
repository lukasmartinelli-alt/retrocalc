#ifndef CALC_H_
#define CALC_H_

#include <iosfwd>

/**
 * Performs a simple arithmetic operation on two values
 * @param value1 First value for the operation
 * @param value2 Second value for the operation
 * @param operatorSymbol The operation to apply to the values (+, -, /, *)
 * @return Result of operation
 */
int calc(int value1, int value2, char operatorSymbol);
/**
 * Read an arithmetic expression from a istream and calculate the result.
 * The expression has to be in the format "{value1} {operatorSymbol} {value2}"
 * @param in Stream to read the expression from
 * @return Result of operation
 */
int calc(std::istream &in);

#endif
