#include "torrecartoni.h"


bool verifica(cartone*c, torre*cur, int i) {
	int TOT = 0;
	for (int h =0;h<cur->size;h++){
		TOT += c[cur->c_ids[h]].p;
	}
	if (c[i].l < TOT) {
		return false;
	}
	return true;
}

void TorreCartoni(int n, cartone*c, int s, torre *cur, torre *best, bool *usati) {
	if (s == n) {
		if (cur->a > best->a) {
			best->a = cur->a;
			best->size = cur->size;
			memcpy(best->c_ids, cur->c_ids, n * sizeof(int));
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (usati[i] == 0) {
			if (verifica(c, cur, i)) {

				cur->a += c[i].a;
				cur->c_ids[cur->size] = i;
				++cur->size;
				usati[i] = 1;

				TorreCartoni(n, c, s + 1, cur, best, usati);
			}
			else {
				TorreCartoni(n, c, n, cur, best, usati);

			}
		}
	}
	return;
}