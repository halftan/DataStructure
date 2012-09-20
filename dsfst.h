#ifndef DSFST_H
#define DSFST_H

typedef int elemtype;

#define INIT_SIZE 10
#define STEP_SIZE 10
#define MAX_SIZE 2000


#define LIST_TOO_LONG 5
#define DELETE_FAIL 7
#define SUCCESS 1

typedef struct SeqList{
	elemtype *list;
	int length;
}SeqList;

int sq_delete(int list[],int *p_n,int i);

SeqList* SListInit(void);
int SListPushBack(SeqList *list,elemtype e);
int SListDelete(SeqList *list,int pos);
void SListPrint(SeqList *list);
void SListDestroy(SeqList *list);
void* ResizeAndInit(void *Src,size_t OriSize,size_t NewSize);
int TextbookAdapter_delete(SeqList *list,int pos);
#endif