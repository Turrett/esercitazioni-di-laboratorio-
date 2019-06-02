#include "monete.h"

int main(void) {
	int size = 6;
	int t []= { 50,20,10,5,2,1 };
	int budget = 233;
	int *a = Monete(t, size, budget);
	for (int i = 0; i < size; i++) {
		printf("%d : %d \n", t[i], a[i]);
	}
	return 0;
}