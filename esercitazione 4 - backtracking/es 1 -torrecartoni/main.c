#include "torrecartoni.h"



int main(void) {

	cartone c[] = { {.p = 10,.a = 20,.l = 40 }, {.p = 10,.a = 10,.l = 8}, {.p = 9,.a = 3,.l = 5} };
	int n = (sizeof(c) / sizeof(cartone));
	torre cur = { .a = 0,.c_ids = malloc(n * sizeof(int)),.size = 0 };
	torre best = { .a = 0,.c_ids = malloc(n * sizeof(int)),.size = 0 };
	memset(cur.c_ids, 0, n*sizeof(int));
	memset(best.c_ids, 0, n*sizeof(int));
	int s = 0;
	bool usati[] = { 0,0,0 };
	TorreCartoni(n, c, s, &cur, &best, usati);
	for (int i =0;i<best.size;i++)
	printf("%d \n\r ", best.c_ids[i]);
	printf("altezza:%d", best.a);

	free(usati);
	free(cur.c_ids);
	free(best.c_ids);
	return 0;

}