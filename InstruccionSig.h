/*
 * InstruccionSig.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONSIG_H_
#define INSTRUCCIONSIG_H_

#include "Instruccion.h"

class InstruccionSig: public Instruccion {
public:
	InstruccionSig(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionSig(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
			  int* instPtr){
		*dataPointer +=1;
	}
};

#endif /* INSTRUCCIONSIG_H_ */
