#include <stdio.h>

void crono(int milli, int *minuti, int *secondi, int*millisecondi) {
	*secondi = milli / 1000;
	*millisecondi = milli % 1000;
	*minuti = *secondi / 60;
	*secondi %= 60;
	return;
}

int main(void) {
	int millisecondi = 61320;
	int m=0;
	int s=0;
	int mi=0;
	crono(millisecondi, &m, &s, &mi);
	return;

}