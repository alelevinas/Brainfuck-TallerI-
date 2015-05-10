/*
 * InstruccionWhileInit.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONWHILEINIT_H_
#define INSTRUCCIONWHILEINIT_H_

#include "Instruccion.h"

class InstruccionWhileInit: public Instruccion {
	int posFin; //La posicion del ] en el vector de instrucciones

public:
	InstruccionWhileInit(char representacion,const char* codigoCpp)
	: Instruccion(representacion, codigoCpp){
		this->posFin=-1;
	}
	virtual ~InstruccionWhileInit(){}

	void setPosFin(int posFin){
		this->posFin=posFin;
	}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
						  int* instPtr){
		if ((*data)[*dataPointer%n] == 0)
			*instPtr = posFin; //El Brainfuck se encarga de aumentar el IP
	}
};

#endif /* INSTRUCCIONWHILEINIT_H_ */
