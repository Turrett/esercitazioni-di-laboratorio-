
#define _CRT_SECURE_NO_WARNINGS
#include "liste_in.h"
#include <string.h>
#include <stdio.h>

list no_rep(list l) {
	list l1 = l;
	list l3 = NULL,tmp=NULL;
	
	while (l1 != NULL) {
		
		bool a = true;

		while (l3 != NULL) {
			if (l1->value == l3->value) {
				a = false;
			}
			l3 = l3->next;
		}
		l3 = tmp;
		if (a == true) {
			l3 = Cons(l1->value, l3);
		}
		tmp = l3;
		l1 = l1->next;
	}

	return l3;
			
}

list LoadList(const char *filename) {
	list head = NULL;
	FILE*f = fopen(filename, "r");
	if (f == NULL) {
		return (EmptyList);
	}
	element a = 0;
	bool b = 0;
	while (fscanf(f, "%d", &a)==1) {
		head = Cons(a, head);
		b = 1;
	}
	if (b == 0) {
		return (EmptyList);
	}
	fclose(f);
	return head;
}

void FreeList(list l) {
	list tmp;
	while (!IsEmpty(l)) {
		tmp = l;
		l = Tail(l);
		free(tmp);
	}
	return;
}

list Intersect(list l1, list l2) {
	list p1 = l1;
	list p2 = l2;
	list p3 = NULL;
	while (p1 != NULL) {
		p2 = l2;
		while (p2 != NULL) {
			if (p1->value == p2->value) {
				p3 = Cons(p1->value, p3);
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return p3;
}

list IntersectNoRep(list l1, list l2) {
	list p1 = l1;
	list p2 = l2;
	list p3 = NULL;
	while (p1 != NULL) {
		p2 = l2;
		while (p2 != NULL) {
			if (p1->value == p2->value) {
				p3 = Cons(p1->value, p3);
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	p3 = no_rep(p3);
	return p3;
}

list Diff(list l1, list l2) {
	list p1 = l1;
	list p2 = l2;
	list p3 = NULL;
	while (p1 != NULL) {
		p2 = l2;
		bool a = true;
		
		while (p2 != NULL) {
			if (p1->value == p2->value) {
				a = false;
			}
			p2 = p2->next;
		}
		if (a==true) {
			list t;
			t = malloc(sizeof(item));
			t->value = Copy(p1->value);
			t->next = p3;
			p3 = t;
		}
		p1 = p1->next;
	}
	
	return p3;
}


list DiffNoRep(list l1, list l2) {
	list p1 = l1;
	list p2 = l2;
	list p3 = NULL;
	while (p1 != NULL) {
		p2 = l2;
		bool a = true;

		while (p2 != NULL) {
			if (p1->value == p2->value) {
				a = false;
			}
			p2 = p2->next;
		}
		if (a == true) {
			list t;
			t = malloc(sizeof(item));
			t->value = Copy(p1->value);
			t->next = p3;
			p3 = t;
		}
		p1 = p1->next;
	}
	p3 = no_rep(p3);
	return p3;
}

element MaxElement(list l1) {
	int a = INT_MIN;
	while (l1 != 0) {
		if (a < l1->value) {
			a = l1->value;
		}
		l1 = l1->next;
	}
	return a;
}
void main(void) {
	char str1[] = "data_00.txt";
	char str2[] = "data_01.txt";
	list a = LoadList(str1);
	list b = LoadList(str2);
	list c = Intersect(a, b);
	list d = Diff(a, b);
	element num = MaxElement(LoadList(str1));
	FreeList(c);

}