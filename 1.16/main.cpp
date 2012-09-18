/*
 * main.cpp
 *
 *  Created on: 2012-9-18
 *      Author: HalFtaN
 */

#include "llist.h"
#include <cstdio>
#include <cstdlib>

int comp(const void *a, const void *b) {
	return *(int*) a - *(int*) b;
}
int main(void) {
	lnode *lista = ListInit(0);
	lnode *listb = ListInit(0);
	int i = 0;
	while (++i < 4) {
		int j;
		scanf("%d", &j);
		push_back(lista, j);
	}
	i = 0;
	while (++i < 5) {
		int j;
		scanf("%d", &j);
		push_back(listb, j);
	}
	printlist(lista);
	printlist(listb);
	fflush(0);
	lista = lsort(lista, comp);
	listb = lsort(listb, comp);
	printlist(lista);
	printlist(listb);
	fflush(0);
	lnode *listc = merge(lista, listb);
	WipeOut(lista);
	WipeOut(listb);
	printlist(listc);
	fflush(0);
	WipeOut(listc);
	return 0;
}

