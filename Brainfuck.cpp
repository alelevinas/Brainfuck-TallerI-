/*
 * Brainfuck.cpp
 *
 *  Created on: May 7, 2015
 *      Author: ale
 */
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> //remove_if
#include <stack>
#include <cstdlib>

#include "Brainfuck.h"
#include "InstruccionFactory.h"
#include "definiciones.h"
#include "InstruccionWhileInit.h"
#include "InstruccionWhileFin.h"
#include "InstruccionDebug.h"

Brainfuck::Brainfuck(unsigned int n) {
	dataSize = n;
	dataPtr = 0;
	instPtr = 0;
	data = new std::vector<signed char>(n,0); // TODO solo deberia reservar si se va a ejecutar...
}

Brainfuck::~Brainfuck() {
	delete data;
	std::vector<Instruccion*>::iterator it;
	for (it=instructions.begin(); it!=instructions.end(); ++it)
		delete (*it);
}

void Brainfuck::ejecutar(){
	//mandar todos los steps aumentando el PI cada vez
	InstruccionDebug deb(DEBUGG, DEBUGGCPP);
	int tmp;
	dataPtr=0;
	instPtr=0;
	//std::vector<Instruccion*>::iterator it;
	//for (it=instructions.begin(); it!=instructions.end(); ++it){
	while ((unsigned int) instPtr < instructions.size()){
		instructions[instPtr]->step(dataSize,&dataPtr,data,&instPtr);
		if (instPtr < 0){
			//std::cerr << "Salimoo\n";
			return;
		}
		//++instPtr;
		tmp = ++instPtr;
		deb.step(dataSize,&dataPtr,data,&instPtr);
		std::cerr << std::endl;
		instPtr =tmp;
	}
	//std::cerr << "\nAhora el debug\n";
	//InstruccionDebug deb(DEBUG, DEBUGCPP);
	//deb.step(dataSize,&dataPtr,data,&instPtr);
}

void Brainfuck::compilar(){
	std::stringstream ss;
	ss << dataSize;
	std::string enca(ENCABEZADOCPP);

	enca.replace(enca.find("<<N>>"),5,ss.str());
	enca.replace(enca.find("<<N>>"),5,ss.str());
	//std::replace( enca.begin(), enca.end(),std::string("<<N>>"),std::string(dataSize));

	std::cout << enca;

	std::vector<Instruccion*>::iterator it;
	for (it=instructions.begin(); it!=instructions.end(); ++it){
		std::cout << (*it)->getCodigoCpp() << "\n";
	}

	std::cout << FINCODIGOCPP;
}


std::istream& operator>>(std::istream& str, Brainfuck& data) {
	std::string line;

	std::stringstream iss;

	std::string acumulado = ""; //guardo solo las instrucciones
	std::string tmp = "";

	while (!str.eof() && str.good()) {
		if (getline(str, line)) {
			iss.clear();
			iss.str("");
			iss << line;
			tmp.clear();
			if (getline(iss,tmp, '#')){ //desestimo lo que hay luego del #
				tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace),
						  tmp.end());
				/*remove_if tira los espacios al fondo y devuelve un puntero
				*a donde deveria terminar el string, entonces elimino desde
				*donde deberia terminar hasta el final que estan los espacios*/
				acumulado += tmp;
			}
		}
	}
	data.crearInstrucciones(acumulado);
	return str;
}

void Brainfuck::crearInstrucciones(std::string& instrucciones){
	InstruccionFactory ifactory;
	std::stack<int> posWhiles;
	int posUltimoWhileInit = -1;
	//InstruccionWhileInit* tmpInit;
	//InstruccionWhileFin* tmpFin;

	int pos;
	std::string::iterator it;
	for ( it=instrucciones.begin(), pos = 0; it!=instrucciones.end(); ++it, ++pos ){
		instructions.push_back(ifactory.create(*it));
		if (*it == WHILEINIT)
			posWhiles.push(pos);
		else if (*it == WHILEFIN){
			posUltimoWhileInit = posWhiles.top();
			posWhiles.pop();
			((InstruccionWhileInit*) instructions[posUltimoWhileInit])
					->setPosFin(pos);

			((InstruccionWhileFin*)instructions[pos])
					->setPosInit(posUltimoWhileInit);

			std::cerr << "WHILE de " << posUltimoWhileInit << " a " << pos << std::endl;
		}
	}
}
