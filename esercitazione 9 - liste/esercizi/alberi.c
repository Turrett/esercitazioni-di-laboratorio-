#include "tree.h"
#include <stdlib.h>
#include <string.h>

tree BstInsert(const element *e, tree t) {
	if (IsEmpty(t)) {
		t = ConsTree(e, EmptyTree(), EmptyTree());
		return t;
	}
	tree tmp=t;
	while (!IsEmpty(tmp)) {
		if (*GetRoot(tmp) >= *e) {
			if (IsEmpty(tmp->left)) {
				tmp->left = ConsTree(e, EmptyTree(), EmptyTree());
				tmp = Left(tmp);
			}
			tmp = tmp->left;
		}
		
		else{
			if (IsEmpty(tmp->right)) {
				tmp->right =ConsTree(e, EmptyTree(), EmptyTree());
				tmp = Right(tmp);
			}
			tmp = tmp->right;
		}
	}
	return t;
}

tree BstInsertRec(const element *e, tree t) {
	tree tmp = t;
	if (IsEmpty(t)) {
		t = ConsTree(e, EmptyTree(), EmptyTree());
		return t;
	}

	if (*GetRoot(t) >= *e) {
		t->left = BstInsertRec(e, t->left);
	}

	else {
		t->right = BstInsertRec(e, t->right);
	}
	return t;
}

int ContaDominanti(tree t)
{
	int a=0;
	if (IsEmpty(t)) {
		return a;
	}

	if (!IsLeaf(t)) {
		element l = 0, r = 0 ,x=0;
		if (!IsEmpty(Left(t)))
			l = Left(t)->value;
		if (!IsEmpty(Right(t)))
			l = Right(t)->value;
		x = r + l;
		if (x < t->value)a++;
	}
		a += ContaDominanti(Left(t));
		a += ContaDominanti(Right(t));
		return a;
}
//BST MAX

element *BstMax(tree t) {
	if (IsEmpty(t))
		return NULL;
	while (!IsEmpty(Right(t))) {
		t = Right(t);
	}

	return &t->value;


}
//MAX

void MaxRec(tree t, element*a) {
	if (IsEmpty(t))
		return;
	if (*a < t->value)
		*a = t->value;

		MaxRec(Left(t), a);
		MaxRec(Right(t), a);
		
}


element *Max(tree t) {
	if (IsEmpty(t))
		return NULL;
	
	element *val = GetRoot(t);
	MaxRec(t, val);

	return val;
}

element *BstMin(tree t) {
	if (IsEmpty(t))
		return NULL;
	while (!IsEmpty(Left(t))) {
		t = Left(t);	
	}

	return &t->value;


}
//MIN

void MinRec(tree t, element*a) {
	if (IsEmpty(t))
		return;
	if (*a > t->value)
		*a = t->value;

	MinRec(Left(t), a);
	MinRec(Right(t), a);

}

element *Min(tree t) {
	if (IsEmpty(t))
		return NULL;

	element *val = GetRoot(t);
	MinRec(t, val);

	return val;
}

//BST DELETE
void read (tree t, element *e, size_t *size, element *elim) {
	if (t->value!=*elim&&!IsEmpty(t)) {
		++(*size);
		e = realloc(e,sizeof(element)*(*size));
		e[(*size) - 1] = t->value;
	}
	if(!IsEmpty(Left(t)))
	read(Left(t),e,size,elim);
	if (!IsEmpty(Right(t)))
	read(Right(t),e,size,elim);
	return;

}

tree BstDelete(tree t, const element*e) {
	element*values = malloc(sizeof(element));
	size_t size = 0;
	tree res=EmptyTree();
	read(t, values, &size, e);
	for (size_t i = 0; i < size; i++) {
		res = BstInsertRec(&values[i], res);
	}
	return res;
}

int main(void) {

	// Test delle funzioni
	element e[] = { 4, 0, 1, 2, 3, 7, 8, 12, 1 };
	int e_size = sizeof(e) / sizeof(element);

	// BstInsertRec
	tree bir = EmptyTree();
	for (int i = 0; i < e_size; ++i) {
		bir = BstInsertRec(&e[i], bir);
	}

	return 0;
}