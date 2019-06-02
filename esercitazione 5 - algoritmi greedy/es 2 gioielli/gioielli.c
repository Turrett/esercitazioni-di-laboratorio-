#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int codice; float peso; float prezzo; } Gioiello;

void Gioielli(const char*filename, float b) {
	if (filename == NULL)
		return;
	FILE*f = fopen(filename, "r");
	size_t len = 0;
	Gioiello *a = malloc (sizeof(Gioiello));
	Gioiello *scelti =malloc (sizeof(Gioiello));
	Gioiello tmp;

	size_t h = 0;
	float spesa = 0;
	float peso_tot = 0;

	//copy file into the structs 
	while (1) {
		if (fscanf(f,"%i %f %f",&tmp.codice, &tmp.peso, &tmp.prezzo) != 3)
			break;
		memcpy(&a[len], &tmp, sizeof(Gioiello));
		++len;
		a = realloc(a, (len+1)*sizeof(Gioiello));
	}
	

	//choice of the jewel
	for (int i = 0; i < len ; i++) {
		if ((a[i].prezzo <=(b-spesa))&&(a[i].peso!=0))
		{
			scelti[h] = a[i];
			h++;
			scelti = realloc(scelti, (h + 1) * sizeof(Gioiello));
			spesa += a[i].prezzo;
			peso_tot += a[i].peso;
			i = -1;
			a[i].peso = 0;
		}
	}
	
	//print 
	printf("i Gioielli scelti sono:\n");
	for (size_t i = 0; i < h; i++) {
		printf("ID:%d --- PESO:%f --- COSTO:%f \n", a[i].codice, a[i].peso, a[i].prezzo);
	}
	printf("percio' la spesa totale sarà di %f euro per acquistare %f grammi",spesa,peso_tot);


	free(a);
	free(scelti);
	


	
}

int main(void) {
	char filename[] = "gioielli.txt";
	int budget = 130;
	Gioielli(filename, budget);
	return 0;
}