#include "minimo.h"

int minimo(int*vec, int len) {
	len -= 1;
	if (len == 0) return vec[len];
	int min = minimo(vec, len);
	if (vec[len] <= min) return vec[len];
	return min;
}