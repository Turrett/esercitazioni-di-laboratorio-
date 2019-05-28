#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
	unsigned int p;
	unsigned int a;
	unsigned int l;
}cartone;

typedef struct {
	unsigned a;
	int *c_ids;
	int size;
}torre;

extern bool verifica(cartone*c, torre*cur, int i);

extern void TorreCartoni(int n, cartone *c, int s, torre *cur, torre *best, bool *usati);