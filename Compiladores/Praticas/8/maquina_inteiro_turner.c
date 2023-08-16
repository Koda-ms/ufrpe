#include <stdio.h>
#include <time.h>

#define N 100000000

#define fim_string -1
#define AP -2 //Abre Parenteses
#define FP -3 //Fecha Parenteses
#define K -4
#define S -5
#define I -6
#define B -7
#define C -8
#define D -9
#define E -10
#define F -11
#define Y -12

/*
 * Entrada SK
 */
static int entrada[N] = {D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, AP, D, AP, F, B, I, AP, S, I, I, FP, FP, I, AP, B, AP, F, B, I, AP, S, I, I, FP, FP, I, FP, AP, K, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, FP, K, FP, fim_string};

static int saida[N];

void printar_array(unsigned int *array1) {
   int i;
   unsigned int fimString = -1;
   for(i = 0;array1[i] != fimString;i++){
       switch (array1[i]){
           case S:
               printf("S");
               break;
           case K:
               printf("K");
               break;
            case I:
                printf("I");
                break;
            case B:
                printf("B");
                break;
            case C:
                printf("C");
                break;
            case D:
                printf("D");
                break;
            case E:
                printf("E");
                break;
            case F:
                printf("F");
                break;
            case Y:
                printf("Y");
                break;
           case FP:
               printf(")");
               break;
           case AP:
               printf("(");
               break;
           case fim_string:
                break;
           default:
               printf("%u ", array1[i]);
       }
   }
   printf("\n");
}

/*
 * Remove o parenteses da posição 0 e seu oposto
 */

void remove_parenteses(int *array1){
    int p = 0;
    int paren = 1;
    while (paren) {
        array1[p] = array1[p+1];
        p++;
        if(array1[p] == AP){
            paren++;
        }else if(array1[p] == FP){
            paren--;
        }
    }
    p--;
    while(array1[p+1] != fim_string && array1[p+2] != fim_string){
        array1[p] = array1[p+2];
        p++;
    }
    array1[p] = fim_string;
}

/*
 * Procura o fim do conjunto de inteiros
 */
void casa_parenteses(int* array1, int* p) {
    int paren = 1;
    int a = *p;
    while (paren) {
        unsigned int c  = array1[a];
        if(c == AP){
            paren++;
        }else if(c == FP){
            paren--;
        }
        a++;
    }
    *p = a;
}

/*
 * Verifica se a posicao do array é um inteiro ou um conjunto de inteiros
 */
void acha_argumento(int *array1, int *p){
    int c = (*p)++;
    if (array1[c] == AP) {
        casa_parenteses(array1,p);
    }
}

/*
 * Kab = a
 */

void reduz_K(int* array1, int* array2) {
    int A, nA;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);

    nA = n-1;
    acha_argumento(array1,&n);

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Sabc = ac(bc)
 */
void reduz_S(int *array1, int *array2) {
    int rA, nA;
    int rB, nB;
    int rC, nC;
    int n = 1;
    rA = n;
    acha_argumento(array1,&n);
    nA = n-1;
    rB = n;
    acha_argumento(array1,&n);
    nB = n-1;
    rC = n;
    acha_argumento(array1,&n);
    nC = n-1;

    int k = 0;
    int i;

    for (i = rA; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = rC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = rB; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = rC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }
    array2[k] = FP;
    k++;
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

/*
 * I a = a
 */
void reduz_I(int *array1, int *array2){
    int k = 0;

    for (int n = 1; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * B a b c = a (b c)
 */
void reduz_B(int *array1, int *array2){
    int Ar, nA;
    int Br, nB;
    int Cr, nC;
    int n = 1;

    Ar = n;
    acha_argumento(array1,&n);
    nA = n-1;
    Br = n;
    acha_argumento(array1,&n);
    nB = n-1;
    Cr = n;
    acha_argumento(array1,&n);
    nC = n-1;

    int k = 0;
    int i;

    for (i = Ar; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Br; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = Cr; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (n=n; array1[n] != fim_string; n++){
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * C a b c = a c b
 */
void reduz_C(int *array1, int *array2){
    int Ar, nA;
    int Br, nB;
    int Cr, nC;
    int n = 1;

    Ar = n;
    acha_argumento(array1,&n);
    nA = n-1;
    Br = n;
    acha_argumento(array1,&n);
    nB = n-1;
    Cr = n;
    acha_argumento(array1,&n);
    nC = n-1;

    int k = 0;
    int i;

    for (i = Ar; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = Cr; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = Br; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (n=n; array1[n] != fim_string; n++){
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
* D a b c d => a (b d) (c d)
*/ 
void reduz_D(int *array1, int *array2){
    int Ar, nA;
    int Br, nB;
    int Cr, nC;
    int Dr, nD;
    int n = 1;

    Ar = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    Br = n;
    acha_argumento(array1, &n);
    nB = n - 1;
    Cr = n;
    acha_argumento(array1, &n);
    nC = n - 1;
    Dr = n;
    acha_argumento(array1, &n);
    nD = n - 1;

    int k = 0;
    int i;

    for (i = Ar; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Br; i <= nB; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Dr; i <= nD; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    array2[k] = AP;
    k++;

    for (i = Cr; i <= nC; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Dr; i <= nD; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (n = n; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
* E a b c d => a b (c d)
*/
void reduz_E(int *array1, int *array2){
    int Ar, nA;
    int Br, nB;
    int Cr, nC;
    int Dr, nD;
    int n = 1;

    Ar = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    Br = n;
    acha_argumento(array1, &n);
    nB = n - 1;
    Cr = n;
    acha_argumento(array1, &n);
    nC = n - 1;
    Dr = n;
    acha_argumento(array1, &n);
    nD = n - 1;

    int k = 0;
    int i;

    for (i = Ar; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Br; i <= nB; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Cr; i <= nC; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Dr; i <= nD; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (n = n; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
* F a b c d => a (b d) c
*/
void reduz_F(int *array1, int *array2){
    int Ar, nA;
    int Br, nB;
    int Cr, nC;
    int Dr, nD;
    int n = 1;

    Ar = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    Br = n;
    acha_argumento(array1, &n);
    nB = n - 1;
    Cr = n;
    acha_argumento(array1, &n);
    nC = n - 1;
    Dr = n;
    acha_argumento(array1, &n);
    nD = n - 1;

    int k = 0;
    int i;

    for (i = Ar; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Br; i <= nB; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Dr; i <= nD; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (i = Cr; i <= nC; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (n = n; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
* Y a => a (Y a)
*/
void reduz_Y(int *array1, int *array2){
    int Ar, nA;
    int n = 1;

    Ar = n;
    acha_argumento(array1, &n);
    nA = n - 1;

    int k = 0;
    int i;

    for (i = Ar; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    array2[k] = Y;
    k++;

    for (i = Ar; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (n = n; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

int main(){
    int *array1, *array2, *array3;
    array1 = entrada;
    array2 = saida;
    while(array1[1] != fim_string){
        switch (array1[0]){
            case AP:
                remove_parenteses(array1);
                array2[0] = fim_string;
                break;
            case K:
                reduz_K(array1, array2);
                break;
            case S:
                reduz_S(array1, array2);
                break;
            case I:
                reduz_I(array1, array2);
                break;
            case B:
                reduz_B(array1, array2);
                break;
            case C:
                reduz_C(array1, array2);
                break;
            case D:
                reduz_D(array1, array2);
                break;
            case E:
                reduz_E(array1, array2);
                break;
            case F:
                reduz_F(array1, array2);
                break;
            case Y:
                reduz_Y(array1, array2);
                break;
            default:
                break;
        }
        array3 = array1;
        array1 = array2;
        array2 = array3;
    }
    printar_array(array1);
    float clks = CLOCKS_PER_SEC;
    printf("\nTempo = %f", (clock()/clks));
    return 0;
}
