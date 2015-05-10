/*
 * InstruccionIn.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONIN_H_
#define INSTRUCCIONIN_H_

#include "Instruccion.h"

class InstruccionIn: public Instruccion {
public:
	InstruccionIn(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionIn(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
			  int* instPtr){
		char c = std::cin.get();
		(*data)[*dataPointer%n] = std::cin.eof() ? 0 : c;
	}
};

#endif /* INSTRUCCIONIN_H_ */
