#define _CRT_SECURE_NO_WARNINGS

#include "liste_int.h"

#include <stdio.h>

void FreeList(list l) {
    list tmp;
    while (!IsEmpty(l)) {
        tmp = l;
        l = Tail(l);
        free(tmp);
    }
}

list LoadList(const char *filename) {
    
    FILE *f;
    f = fopen(filename, "r");

    if (!f) {
        return NULL;
    }

    list l = EmptyList();
    while (1) {
        element tmp;
        if (1 != fscanf(f, "%d", &tmp)) {
            break;
        }
        l = Cons(tmp, l);
    }

    return l;
}

bool Contain(list l, element e)
{
    bool found = false;
    while (!IsEmpty(l) && !found)
    {
        found = (Head(l) == e);
        l = Tail(l);
    }
    return found;
}

list Intersect(list l1, list l2)
{
    element cur;
    list intersection = EmptyList();
    while (!IsEmpty(l1))
    {
        cur = Head(l1);
        if (Contain(l2, cur)) {
            intersection = Cons(cur, intersection);
        }
        l1 = Tail(l1);
    }
    return intersection;
}


bool ContainNoPrimitive(list l, element e)
{
    bool found = false;
    while (l != NULL && !found)
    {
        found = (l->value == e);
        l = l->next;
    }
    return found;
}

list Diff(list l1, list l2) {
    element cur;
    list diff = NULL, temp;
    while (l1 != NULL)
    {
        cur = l1->value;
        if (!ContainNoPrimitive(l2, cur))
        {
            temp = (list)malloc(sizeof(item));
            temp->value = cur;
            temp->next = diff;
            diff = temp;
        }
        l1 = l1->next;
    }
    return diff;
}

list IntersectNoRep(list l1, list l2) {

}

list DiffNoRep(list l1, list l2) {

}

int main() {
    list l1 = LoadList("data_00.txt");
    list l2 = LoadList("data_01.txt");

    list i = Intersect(l1, l2);
    list d = Diff(l1, l2);

    FreeList(l1);
    FreeList(l2);
    FreeList(i);
    FreeList(d);

    return 0;
}