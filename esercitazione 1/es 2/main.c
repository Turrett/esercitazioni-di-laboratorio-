#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int i;
	int a = 1;
	for (i=1;i<argc;i++) {
		a *= atoi(argv[i]);
	}
	printf("il risulatato e' %d", a);
	return 0;
}