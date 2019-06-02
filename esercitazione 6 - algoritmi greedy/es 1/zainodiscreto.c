#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int p;
	int v;
}oggetto;

oggetto * zainodiscreto(oggetto*o, int n, int p, int *cs) {

	oggetto*a = malloc(sizeof(oggetto));
	*cs = 0;
	int best_cost = 0;
	int peso_tot = 0;
	int best = 0;
	int tmp = 0;

	for (int i = 0; i < n; ++i) {
		if (o[i].p != 0) {
			tmp = o[i].v / o[i].p;

			if (best_cost < tmp) {
				best_cost = tmp;
				best = i;
			}
		}
		if ((i == n - 1) && ((p - peso_tot) >= o[best].p)){
			++(*cs);
			a = realloc(a, (*cs) * sizeof(oggetto));
			i = -1;
			peso_tot += o[best].p;
			memcpy(&a[(*cs)-1], &o[best], sizeof(oggetto));
			
			
			best_cost = 0;
			o[best].p = 0;
		}
	}
	return a;
}

void stampa(oggetto*obj, int size) {
	int tot = 0;
	for (int i = 0; i < size; i++) {
		printf("p:\t%d, v:\t%d\n", obj[i].p, obj[i].v);
		tot += obj[i].v;
	}
	printf("totale: %d", tot);
	}

int main(void) {
	int n = 3;
	int p = 50;
	int best_size=0 ;
	oggetto o[] = { {.p = 20,.v = 100},{.p = 10,.v = 60},{.p = 30,.v = 120} };
	oggetto *best = zainodiscreto(o, n, p, &best_size);
	stampa(best, best_size);

	return 0;

}