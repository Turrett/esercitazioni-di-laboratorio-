#include "StazioniServizio.h"

//la moto consuma 0.05 litri/km , il serbatoio � di 30 litri 

bool verifica(piano*cur, double*d, double *p, double m, int n) {
	int maxd = 30 / 0.05;
	int part = 0;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (cur->stazioni[i] == 0) {
			part += d[i];
		}
		if (cur->stazioni[i] == 1) {
			if (part < maxd)return false;
			else part = 0;
			cur->spesa += p[i];
		}
		tot += d[i];
	}


	if ((m - tot) + part > maxd) {
		return false;
	}
	return true;
}



void StazioniServizio(double m, int n, double *d, double *p, int s, double dist, piano *cur, piano *best) {
	if (s == n) {
		if (verifica(cur,d,p,m,n)&& (best->spesa > cur->spesa)) {

			best->spesa=cur->spesa;
			memcpy(best->stazioni, cur->stazioni, n);
		}
		return;
	}

	for (int i = 0; i < 1; i++) {
		if (i == 1) {
			cur->stazioni[s] = 1;
		}
		else cur->stazioni[s] = 0;
		StazioniServizio(m, n, d, p, s + 1, dist, cur, best);
	}
	return;
}