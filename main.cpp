//============================================================================
// Name        : main.cpp
// Author      : Ale Levinas
// Version     :
// Copyright   : Your copyright notice
// Description : Interprete y compilador de BrainFuck
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Brainfuck.h"

#include "InstruccionDebug.h"
#include "InstruccionSumar.h"
#include "InstruccionAnt.h"
#include "InstruccionFin.h"
#include "InstruccionIn.h"
#include "InstruccionOut.h"
#include "InstruccionRestar.h"
#include "InstruccionSig.h"
#include "InstruccionWhileFin.h"
#include "InstruccionWhileInit.h"

#include "definiciones.h"

//using namespace std;

int main(int argc, char * const argv[]) {
	//std::cout << "Hello World!!!" << std::endl; // prints Hello World!!!
/*
	std::cout << "PI ";
	std::cout << std::setfill ('0') << std::setw (8) << std::hex;
	std::cout << 25 << "\n";

	//std::cout << "DP";

	InstruccionWhileInit wi(WHILEINIT,WHILEINITCPP);
	InstruccionWhileFin wf(WHILEFIN, WHILEFINCPP);
	InstruccionSig sig(SIG, SIGCPP);
	InstruccionRestar res(RESTAR,RESTARCPP);
	InstruccionOut out(IMPRIMIR, IMPRIMIRCPP);
	InstruccionIn in(LEER, LEERCPP);
	InstruccionFin fin(FIN, FINCPP);
	InstruccionAnt ant(ANT,ANTCPP);
	InstruccionSumar sum(SUMAR,SUMARCPP);

	InstruccionDebug deb(DEBUG, DEBUGCPP);

	signed char myints[] = {16,2,77,29};
	std::vector<signed char> data (myints, myints + sizeof(myints) / sizeof(char) );

	int instPtr=8;

	wi.step(1600, 2, &data, &instPtr);
	wf.step(1600, 2, &data, &instPtr);
	sig.step(1600, 2, &data, &instPtr);
	res.step(1600, 2, &data, &instPtr);
	out.step(1600, 2, &data, &instPtr);
	in.step(1600, 2, &data, &instPtr);
	ant.step(1600, 2, &data, &instPtr);
	sum.step(1600, 2, &data, &instPtr);
	fin.step(1600, 2, &data, &instPtr);
	deb.step(1600, 2, &data, &instPtr);
*/
	Brainfuck bf(atoi(argv[1]));

	std::ifstream ifs;

	ifs.open(argv[3]);

	if(!ifs.good()){
		std::cout << "No abriste nada idiota\n";
		std::cout << ifs.rdstate();
		return false;
	}

	ifs >> bf;

	ifs.close();

	if (argv[2][0] == 'e')
		bf.ejecutar();
	else if (argv[2][0] == 'c')
		bf.compilar();
	else
		return 1;
	return 0;
}
