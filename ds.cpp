#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "dsfst.h"

int main(void){
	SeqList *list = SListInit();
	int T;
	elemtype e;
	printf("Input the length of list: ");
	scanf("%d",&T);
	while(T--){
		scanf("%d",&e);						//SHOULD BE REVISED FOR THE DATATYPE!
		SListPushBack(list,e);
	}
	SListPrint(list);
	printf("Which one should be deleted: ");
	scanf("%d",&T);
	SListDelete(list,T);
	SListPrint(list);
	SListDestroy(list);
	return 0;
}

SeqList* SListInit(void){
	SeqList *t = (SeqList*)malloc(sizeof(SeqList));
	t->length = 0;
	t->list = (elemtype *)malloc(sizeof(elemtype)*INIT_SIZE);
	memset(t->list,0,sizeof(elemtype)*INIT_SIZE);
	return t;
}

int SListPushBack(SeqList *list,elemtype e){
	int i = 0;
	if(list->length >= MAX_SIZE){
		printf("List too long!\n");
		fflush(0);
		return LIST_TOO_LONG;
	}
	//dynamically resizes memory of the list, whether it grows or shrinks.
	if(list->length % 10 == 9)
		list->list = (elemtype *)ResizeAndInit(list->list,sizeof(elemtype)*list->length,sizeof(elemtype)*(list->length / 10 + 2)*STEP_SIZE);
	
	while(*(list->list + i))
		++i;
	*(list->list + i) = e;
	++list->length;
	return SUCCESS;
}

void SListPrint(SeqList *list){
	int i;
	for(i = 0;i < list->length;++i)
		printf("%d:\t%d\n",i + 1,*(list->list + i));					//SHOULD BE REVISED FOR THE DATATYPE!!
}

void SListDestroy(SeqList *list){
	free(list->list);
	free(list);
}

void* ResizeAndInit(void *Src,size_t OriSize,size_t NewSize){
	void *t = malloc(NewSize);
	memset(t,0,NewSize);
	memcpy(t,Src,OriSize);
	free(Src);
	return t;
}

int SListDelete(SeqList *list,int pos){
	if(TextbookAdapter_delete(list,pos))
		return SUCCESS;
	printf("Deletion failed!\n");
	fflush(0);
	return DELETE_FAIL;
}

int TextbookAdapter_delete(SeqList *list,int pos){
	if(sq_delete(list->list,&(list->length),pos - 1))
		return DELETE_FAIL;
	return SUCCESS;
}

int sq_delete(int list[],int *p_n,int i){
	int j;
	if(i < 0 || i >= *p_n)
		return 1;
	for(j = i + 1;j < *p_n;++j)
		list[j - 1] = list[j];
	--(*p_n);
	return 0;
}