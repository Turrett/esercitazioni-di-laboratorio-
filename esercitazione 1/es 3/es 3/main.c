#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	char c[1000];
	int i = 0;
	scanf("%s", c);
	while ((c + i) != 0) {
		if (*(c + i) >= 'a' || *(c + i) >= 'z') {
			*(c + i) += 'A' - 'a';
		}
		i++;
	}
	return;

}