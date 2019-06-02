#include "monete.h"
int *Monete(int *t, int size, int b) {
	if (b <= 0)return NULL;
	int *a = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		int c = b / t[i];
		a[i] = c;
		b %= t[i];
	}
	return a;
}