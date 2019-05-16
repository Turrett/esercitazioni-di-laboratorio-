#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


int searchocc(FILE *f,char*s) {
	int count=0;
	char c = fgetc(f);
	int len = strlen(s);
	while ( c != EOF) {
		int i = 0;
		bool a = false;
		while(c==*(s+i)){
			a = true;
			i++;
			c = fgetc(f);
		}
		

		if ((i == len) && (a==true)) {
			++count;
		}
		else if (a == false) {
			c = fgetc(f);
		}
	
	}
	return count;
}

int main(void) {
	FILE *f = fopen("manz.txt","rt");
	int a= searchocc(f, "la");
	return 0;

	

}