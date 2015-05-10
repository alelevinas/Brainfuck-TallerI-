/*
 * InstruccionWhileFin.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONWHILEFIN_H_
#define INSTRUCCIONWHILEFIN_H_

#include "Instruccion.h"

class InstruccionWhileFin: public Instruccion {
	int posInit; //La posicion del ] en el vector de instrucciones

public:
	InstruccionWhileFin(char representacion, const char* codigoCpp)
	: Instruccion(representacion, codigoCpp){
		this->posInit=-1;
	}
	virtual ~InstruccionWhileFin(){}

	void setPosInit(int posInit){
		this->posInit=posInit;
	}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
						  int* instPtr){
		if ((*data)[*dataPointer%n] != 0)
			*instPtr = posInit; //El Brainfuck se encarga de aumentar el IP
								//luego de cada instruccion
	}
};

#endif /* INSTRUCCIONWHILEFIN_H_ */
