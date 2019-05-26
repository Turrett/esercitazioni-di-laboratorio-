#include "somma.h"

int somma(int n) {
	int part = n;
	if (n <= 0) return -1;
	if (n == 1)return n;
	part += somma(n - 1);
	return part;
}