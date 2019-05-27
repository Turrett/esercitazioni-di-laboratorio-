#include "torrecartoni.h"

int main(void) {
	int n = 4;
	cartone c[] = { {.p = 10,.a = 20,.l = 40 }, {.p = 10,.a = 10,.l = 8}, {.p = 9,.a = 3,.l = 5} };
	int n = sizeof(c) / sizeof(cartone);
	torre cur = { .a = 0,.c_ids = malloc(n * sizeof(int)),.size = 0 };
	torre best = { .a = 0,.c_ids = malloc(n * sizeof(int)),.size = 0 };

	// Array che tiene traccia dei cartoni usati
	bool *usati;
	usati = calloc(n, sizeof(int));

	// Chiamo la funzione di backtracking
	TorreCartoni(n, c, 0, &cur, &best, usati);

	// Visualizzo su stdout il risultato
	for (int i = 0; i < best.size; i++) {
		printf("%4d\n", best.c_ids[i]);
	}
	printf("Altezza: %d cm\n", best.a);

	// Libero la memoria
	free(cur.c_ids);
	free(best.c_ids);
	free(usati);

	return 0;

}