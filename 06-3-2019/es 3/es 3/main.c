#define _CRT_SECURE_NO_WARNINGS

#include "minimo.h"
#include <string.h>
#include <stdio.h>
int main(void) {
	FILE*f = fopen("dati.txt", "rt");
	int a[100];
	int len=0;
		while (!feof(f)) {
			int tmp = 0;
			fscanf(f, "%d", &tmp);
			a[len] = tmp;
			len++;
		}
	
	int b = minimo(a, len);
	fclose(f);
	return;
}