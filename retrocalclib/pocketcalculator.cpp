#include "pocketcalculator.h"
#include "calc.h"
#include "sevensegment.h"
#include <iostream>
#include <sstream>

void pocketCalc(std::istream &in, std::ostream &out){
	while(in){
		std::string line{};
		if(getline(in,line)){
			std::istringstream is{line};
			printLargeNumber(calc(is), out);
		}
	}
	in.clear();
}

