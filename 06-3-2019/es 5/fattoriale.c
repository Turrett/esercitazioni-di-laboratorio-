#include"fattoriale.h"

long long fattoriale(int n) {
	if (n < 0)return 0;
	if (n == 0)return 1;
	return n * fattoriale(n - 1);
}