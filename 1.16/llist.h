/****************
 * Head File of Linked List
 *
 * Created 2012/9/17 16:30 BY HalFtaN
 */

#ifndef LLIST_H
#define LLIST_H

#include <cstdio>
#include <cstdlib>

typedef int type;

typedef struct lnode{
	type content;
	lnode *next;
	lnode *prev;
} lnode;

typedef struct info{
	type cont;
	lnode *ptr;
} info;

lnode* ListInit(size_t size);
lnode* push_back(lnode *list, type e);
void insert(lnode *list, type e);
void WipeOut(lnode *list);
lnode* merge(lnode *a, lnode *b);
lnode* lsort(lnode* list, int (*func)(const void *a, const void *b));
size_t lGetSize(const lnode *list);
lnode* getBase(lnode *list);
void printlist(lnode *list);
int inc(const void *a, const void *b);
int dec(const void *a, const void *b);
#endif
