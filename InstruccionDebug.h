/*
 * InstruccionDebug.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCIONDEBUG_H_
#define INSTRUCCIONDEBUG_H_

#include <iostream>
#include <iomanip>
#include <algorithm>    // std::for_each

#include "Instruccion.h"

class InstruccionDebug: public Instruccion {
private:
	void imprimir(signed char i);
public:
	InstruccionDebug(char representacion, const char* codigoCpp) :
		Instruccion(representacion, codigoCpp){}
	virtual ~InstruccionDebug(){}

	void step(int n, int* dataPointer, std::vector<signed char>* data,
						  int* instPtr){

		std::cerr << "PI ";
		std::cerr << std::setfill('0') << std::setw(8)
				  << std::uppercase << std::hex;
		std::cerr << *instPtr << "\n";

		std::cerr << "PD ";
		std::cerr << std::setfill('0') << std::setw(8)
				  << std::uppercase << std::hex;
		std::cerr << (*dataPointer)%n << "\n";

		std::vector<signed char>::iterator it;

		std::cerr << "Data\n";
		for (it = data->begin(); it != data->end(); ++it){
			std::cerr << std::setfill('0') << std::setw(2)
					  << std::uppercase << std::hex;
			std::cerr << (int)*it << ' ';
		}
		*instPtr = -1; //El Brainfuck chequea el PI y sale
	}
};

#endif /* INSTRUCCIONDEBUG_H_ */

//for_each (data->begin(), data->end(), this->*InstruccionDebug::imprimir);
/*
void InstruccionDebug::imprimir(signed char i){
	std::cerr << std::setfill('0') << std::setw(2) << std::hex;
	std::cerr << i << " ";
}
*/
