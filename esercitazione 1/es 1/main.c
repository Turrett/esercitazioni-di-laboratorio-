#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc,char *argv[])
{
	int count1=0;
	int count2=0;
	int i = 0;
	char a = argv[1][0];
	char b = argv[2][0];
	while ( argv[3][i]!= 0) {
		if (argv[3][i] == a) {
			count1++;
		}
		if (argv[3][i] == b) {
			count2++;
		}
		i++;
	}
	if (count1 > count2) {
		printf("ci sono piu' lettere %c", a);
	}
	if (count1 <count2) {
		printf("ci sono piu' lettere %c", b);
	}
	if (count1 == count2) {
		printf("le lettere %c e %c sono in egual numero ", a,b);
	}
	return 0;
}