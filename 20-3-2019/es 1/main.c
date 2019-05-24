#include "ombrelloni.h"

int main(void) {
	int n = 6;
	int k = 2;
	unsigned s = 0;
	bool *v = malloc(n * sizeof(bool));
	unsigned cnt = 0;
	unsigned n_slz = 0;
	Ombrelloni(k, n, s, v, cnt,& n_slz);
	return 0;
}