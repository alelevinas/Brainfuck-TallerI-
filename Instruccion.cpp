/*
 * Instruccion.cpp
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#include "Instruccion.h"

Instruccion::Instruccion(const char representacion, const char* codigoCpp) {
	this->representacion = representacion;
	this->codigoCpp += codigoCpp;
}

