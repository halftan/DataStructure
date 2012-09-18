/*
 * llist.cpp
 *
 *  Created on: 2012-9-17
 *      Author: HalFtaN
 *  Implement of llist.h
 */

#include <cstdio>
#include <cstdlib>
#include "llist.h"

lnode* ListInit(size_t size) {
	//returns a new list with its all nodes linked!
	if (size <= 0)
		size = 1;
	lnode *cur, *base;
	base = cur = (lnode*) malloc(sizeof(lnode));
	base->prev = NULL;
	base->next = NULL;
	while (--size > 0) {
		lnode *t = (lnode*) malloc(sizeof(lnode));
		cur->next = t;
		t->prev = cur;
		cur = t;
	}
	cur->next = NULL;
	return base;
}

lnode* push_back(lnode *list, type e) {
	while (list->next != NULL)
		list = list->next;
	lnode *t = (lnode*) malloc(sizeof(lnode));
	t->prev = list;
	t->next = NULL;
	list->next = t;
	list->content = e;
	return t;
}

void WipeOut(lnode *list) {
	list = getBase(list);
	while (list->next != NULL) {
		list = list->next;
		free(list->prev);
	}
	free(list);
}

void insert(lnode *list, type e) {
	lnode *t = (lnode*) malloc(sizeof(lnode));
	t->prev = list;
	t->next = list->next;
	list->next = t;
	t->content = e;
	return;
}

lnode* getBase(lnode *list) {
	while (list->prev != NULL)
		list = list->prev;
	return list;
}

lnode* lsort(lnode* base, int (*func)(const void *a, const void *b)) {
	size_t size = 0, i;
	lnode *t;
	int (*cfc)(const void *a, const void *b);
	base = getBase(base);
	t = base;
	size = lGetSize(base);
	if (size == 0) {
		printf("Error: no elements in list!\n");
		fflush(0);
		return NULL;
	}
	//qsort(base, size + 1, sizeof(lnode), func); sort linked list: Not allowed!
	int ee = 2, tt = 1;
	if ((*func)(&tt, &ee) < 0)
		cfc = inc;
	else
		cfc = dec;
	info iarr[size + 1];
	for (i = 0; t->next; t = t->next, ++i) {
		iarr[i].cont = t->content;
		iarr[i].ptr = t;
	}
	iarr[i].cont = t->content;
	iarr[i].ptr = t;
	qsort(iarr, size, sizeof(info), cfc);
	iarr[0].ptr->prev = NULL;
	for (i = 1; i < size; ++i) {
		iarr[i].ptr->prev = iarr[i - 1].ptr;
		iarr[i].ptr->next = iarr[i + 1].ptr;
		iarr[i - 1].ptr->next = iarr[i].ptr;
	}
	iarr[size].ptr->next = NULL;
	iarr[size].ptr->prev = iarr[size - 1].ptr;
	base = iarr[0].ptr;
	return base;
}

size_t lGetSize(const lnode *list) {
	//Counts the number of node in the linked list!
	size_t size = 0;
	while (list->next != NULL) {
		++size;
		list = list->next;
	}
	return size;
}

lnode* merge(lnode *a, lnode *b) {
	//return a new-merged list base ptr!
	lnode *res = ListInit(1);
	lnode *cur = res;
	a = getBase(a);
	b = getBase(b);

	for (; b->next; b = b->next) {
		while (a->content <= b->content && a->next) {
			cur = push_back(cur, a->content);
			a = a->next;
		}
		cur = push_back(cur, b->content);
	}
	while (a->next) {
		cur = push_back(cur, a->content);
		a = a->next;
	}
	return res;
}

void printlist(lnode *list) {
	int i = 0;
	list = getBase(list);
	while (list->next) {
		printf("%03d:\t%d\n", ++i, list->content);	//Format! should be revised!
		list = list->next;
	}
}

int inc(const void* a, const void* b) {
	return ((const info*) a)->cont - ((const info*) b)->cont;
}

int dec(const void* a, const void* b) {
	return ((const info*) b)->cont - ((const info*) a)->cont;
}
