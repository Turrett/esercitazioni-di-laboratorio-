#include "liste.h"
#include <stdio.h>
#include <string.h>

list InsertBack(list l, const element *e) {
	list tmp = l;
	while (tmp != NULL) {
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(item));
	tmp->value = Copy(e);
	tmp->next = NULL;
	return l;
}

void StampaLista(list l) {
	while (!IsEmpty(l)) {
		printf("%s %s %d %s %s %s \n", l->value.nome, l->value.via, l->value.civico, l->value.citta, l->value.provincia, l->value.cap);
		l = tail(l);
	}
	return;
}

element * Cerca(list l, const char *nome) {
	element *a = NULL;
	size_t len =strlen(nome);

	while (!IsEmpty(l)) {
		if (strcmp(l->value.nome, nome)==0) {
			a = &l->value;
		}
		l = Tail(l);
	}
	return a;
}

list Elimina(list l, const char *nome){
	list tmp = EmptyList();

	while (!IsEmpty(l)) {
		if (strcmp(l->value.nome, nome) != 0) {
			tmp = InsertBack(tmp, &l->value);
		}
		l = Tail(l);
	}
	return tmp;
}

list Filtra(list l, const char *citta) {
	list a = EmptyList;
	while (!IsEmpty(l)) {
		if (strcmp(l->value.citta, citta) == 0)
		{
			a = InsertBack(a, &l->value);
		}
		l = l->next;
	}
	return a;
}
list reverse(list l) {
	list a = EmptyList();
	while (!isEmpty(l)) {
		a = Cons(&l->value, a);
		l = l->next;
	}
	return  a;
}

list Append(list l1, list l2) {
	list l3=EmptyList() ;
	
	while (!IsEmpty(l1)) {
		l3 = InsertBack(l3, &l1->value);
		l1 = l1->next;
	}
	while (!IsEmpty(l2)) {
		l3 = InsertBack(l3, &l2->value);
		l2 = l2->next;
	}
	return l3;
}

list AppendMod(list l1, list l2) {
	if (isEmpty(l1)) {
		return l2;
	}
	list tmp = l1;
	while (!isEmpty(Tail(tmp))) {
		tmp = tmp->next;
	}
	tmp->next = l2;
	return l1;
}



