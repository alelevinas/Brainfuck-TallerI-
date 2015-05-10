/*
 * definiciones.h
 *
 *  Created on: May 8, 2015
 *      Author: ale
 */

#define SIG '>'
#define SIGCPP "dataptr += 1;"

#define ANT '<'
#define ANTCPP "dataptr += -1;"

#define SUMAR '+'
#define SUMARCPP "data[AT(dataptr)] += 1;"

#define RESTAR '-'
#define RESTARCPP "data[AT(dataptr)] += -1;"

#define IMPRIMIR '.'
#define IMPRIMIRCPP "std::cout << data[AT(dataptr)];"

#define LEER ','
#define LEERCPP "c = std::cin.get();\ndata[AT(dataptr)] = std::cin.eof() ? 0 : c;"

#define WHILEINIT '['
#define WHILEINITCPP "while(data[AT(dataptr)]) {"

#define WHILEFIN ']'
#define WHILEFINCPP "}"

#define FIN '$'
#define FINCPP "return 0;"

#define DEBUGG '@'
#define DEBUGGCPP "return 0;"

#define ENCABEZADOCPP "#include <iostream>\n#include <vector>\n\n\n#define N <<N>>\n#define AT(x) ((x) % ​<<N>> ​)\n\n\nint main(int argc, char *argv[]) {\nint dataptr = 0;\nsigned char c = 0;\nstd::vector<signed char> data(N, 0);\n"
#define FINCODIGOCPP "return 0;\n}"

/*#define ENCABEZADO_INCLUDES "#include <iostream>\n#include <vector>\n\n\n"
#define ENCABEZADO_DEFINE_N "#define N "
#define ENCABEZADO_DEFINE_AT "\n#define AT(x) ((x) % ​%d ​)\n\n\n"
#define ENCABEZADO_CUERPO "int main(int argc, char *argv[]) {\nint dataptr = 0;\nsigned char c = 0;\nstd::vector<signed char> data(N, 0);\n"
#define FINCODIGOCPP "return 0;\n}"
*/
