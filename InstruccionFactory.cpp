/*
 * InstruccionFactory.cpp
 *
 *  Created on: May 8, 2015
 *      Author: ale
 */

#include "InstruccionFactory.h"

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

Instruccion* InstruccionFactory::create(const char name){

	switch(name){
	case SIG:
		return new InstruccionSig(SIG, SIGCPP);
		break;
	case ANT:
		return new InstruccionAnt(ANT,ANTCPP);
	case SUMAR:
		return new InstruccionSumar(SUMAR,SUMARCPP);
	case RESTAR:
		return new InstruccionRestar(RESTAR,RESTARCPP);
	case IMPRIMIR:
		return new InstruccionOut(IMPRIMIR, IMPRIMIRCPP);
	case LEER:
		return new InstruccionIn(LEER, LEERCPP);
	case WHILEINIT:
		return new InstruccionWhileInit(WHILEINIT, WHILEINITCPP);
	case WHILEFIN:
		return new InstruccionWhileFin(WHILEFIN, WHILEFINCPP);
	case FIN:
		return new InstruccionFin(FIN, FINCPP);
	case DEBUGG:
		return new InstruccionDebug(DEBUGG, DEBUGGCPP);
	}
	return NULL;
}
