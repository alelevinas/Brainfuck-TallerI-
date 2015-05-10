/*
 * InstruccionSumar.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONSUMAR_H_
#define INSTRUCCIONSUMAR_H_

#include "Instruccion.h"

class InstruccionSumar: public Instruccion {

public:
	InstruccionSumar(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionSumar(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
						  int* instPtr){
		(*data)[*dataPointer%n] += (signed char) 1;
	}
};

#endif /* INSTRUCCIONSUMAR_H_ */
