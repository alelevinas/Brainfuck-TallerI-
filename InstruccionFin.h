/*
 * InstruccionFin.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONFIN_H_
#define INSTRUCCIONFIN_H_

#include "Instruccion.h"

class InstruccionFin: public Instruccion {
public:
	InstruccionFin(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionFin(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
						  int* instPtr){
		*instPtr = -1; //El Brainfuck chequea el IP y sale
	}
};

#endif /* INSTRUCCIONFIN_H_ */
