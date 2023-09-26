#ifndef _PRIMOS_H
#define _PRIMOS_H

typedef void (*FprtProgresso)(unsigned int, unsigned int);

//Informa se um numero eh primo
int QuantosPrimosAtehX(unsigned int x, FprtProgresso prog);

#endif
