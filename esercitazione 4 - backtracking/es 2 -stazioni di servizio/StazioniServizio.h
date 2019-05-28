#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string>

typedef struct { 
double spesa;
int *stazioni; }
piano;

extern bool verifica(piano*cur, double*d, double *p, double m, int n);
extern void StazioniServizio(double m, int n, double *d, double *p, int s, double dist, piano *cur, piano *best);