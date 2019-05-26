
#include "divisione.h"

int divisione(int a, int b) {
	int res = 0;
	if (b <= 0 || a < 0) {
		return -1;
	}
	if (a >= b) {
		res++;
		res+=divisione(a - b, b);
	}
		

	

	return res;
}