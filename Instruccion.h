/*
 * Instruccion.h
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */

#ifndef INSTRUCCION_H_
#define INSTRUCCION_H_

#include <string>
#include <vector>

#define AT(x,n) (x%n)

class Instruccion {
	char representacion;
	std::string codigoCpp;

public:
	explicit Instruccion(const char representacion, const char* codigoCpp);
	virtual ~Instruccion(){}

	virtual void step(int n, int* dataPointer, std::vector<signed char>* data,
					  int* instPtr)=0;

	std::string& getCodigoCpp(){
		return codigoCpp;
	}

	int mod(int n, int dataPtr){
		return (dataPtr<0 ? mod(dataPtr+n,n) : AT(dataPtr,n));
	}
};

#endif /* INSTRUCCION_H_ */
