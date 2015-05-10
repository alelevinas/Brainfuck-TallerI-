/*
 * InstruccionFactory.h
 *
 *  Created on: May 8, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONFACTORY_H_
#define INSTRUCCIONFACTORY_H_

#include "Instruccion.h"

class InstruccionFactory {
public:
	InstruccionFactory(){}
	~InstruccionFactory(){}

	Instruccion* create(const char name);
};

#endif /* INSTRUCCIONFACTORY_H_ */
