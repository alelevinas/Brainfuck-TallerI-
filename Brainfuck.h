/*
 * Brainfuck.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef BRAINFUCK_H_
#define BRAINFUCK_H_

#include <iostream>
#include <vector>
#include <string>

#include "Instruccion.h"
//#define N <<N>>
//#define AT(x) ((x) % <<N>> ​

class Brainfuck {
	unsigned int dataSize;
	int dataPtr;
	int instPtr;
	std::vector<signed char>* data;
	std::vector<Instruccion*> instructions;

public:
	Brainfuck(unsigned int n);
	virtual ~Brainfuck();

	void ejecutar();
	void compilar();

	/*Carga las operaciones procesando el flujo de entrada*/
	friend std::istream& operator>>(std::istream& str, Brainfuck& data);

private:
	void crearInstrucciones(std::string& instrucciones);
};

#endif /* BRAINFUCK_H_ */
