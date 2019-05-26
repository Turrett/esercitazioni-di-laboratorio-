
#include "divNegativa.h"

int divisioneNegativa(int a, int b) {
	int res = 0;
	if (b == 0)
		return INT_MAX;
	if (a >= b && b > 0) {
		res++;
		res += divisioneNegativa(a - b, b);
	}

	if (a >= abs(b) && b < 0) {
		res--;
		res += divisioneNegativa(a + b, b);
	}
	if (a<=-b && b>0) {
		
			res--;
			res += divisioneNegativa(a + b, b);
	}
	if (a <= b && b < 0) {
		res++;
		res += divisioneNegativa(a - b, b);
	}
	return res;
}