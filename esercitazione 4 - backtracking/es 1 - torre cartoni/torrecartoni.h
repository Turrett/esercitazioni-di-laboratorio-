
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


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


extern void TorreCartoni(int n, cartone *c, int s, torre *cur, torre *best, bool *usati);