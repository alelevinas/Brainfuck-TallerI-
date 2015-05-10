/*
 * InstruccionRestar.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONRESTAR_H_
#define INSTRUCCIONRESTAR_H_

#include "Instruccion.h"

class InstruccionRestar: public Instruccion {
public:
	InstruccionRestar(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionRestar(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
							  int* instPtr){
		(*data)[*dataPointer%n] += -1;
		}
};

#endif /* INSTRUCCIONRESTAR_H_ */
