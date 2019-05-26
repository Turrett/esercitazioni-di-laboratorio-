#include "prodotto.h"

int prodottoNegativi(int a, int b) {
	int  c = 0;
	char neg = 1;
	if (b == 0)return 0;
	if (b >= 1) 
		c = a + prodottoNegativi(a, b - 1);

	if (b <= -1)
		c = -a + prodottoNegativi(a, b + 1);
		return c;
}