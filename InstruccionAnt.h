/*
 * InstruccionAnt.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONANT_H_
#define INSTRUCCIONANT_H_

#include "Instruccion.h"

class InstruccionAnt: public Instruccion {
public:
	InstruccionAnt(char representacion, const char* codigoCpp) :
			Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionAnt(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
			  int* instPtr){
		*dataPointer += -1;
	}
};

#endif /* INSTRUCCIONANT_H_ */
