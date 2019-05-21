#include "prodotto.h"

int prodotto(int a, int b) {
	int  c = 0;
	if (a < 0 || b < 0) return -1;
	if (b >= 1) {
		c = a + prodotto(a, b - 1);
	}
		return c;
}