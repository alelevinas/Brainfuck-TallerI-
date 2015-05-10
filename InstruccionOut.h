/*
 * InstruccionOut.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONOUT_H_
#define INSTRUCCIONOUT_H_

#include "Instruccion.h"

class InstruccionOut: public Instruccion {
public:
	InstruccionOut(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionOut(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
			  int* instPtr){
		std::cout << (*data)[*dataPointer%n];
	}
};

#endif /* INSTRUCCIONOUT_H_ */
