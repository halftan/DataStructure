#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* init;
	unsigned int head, tail, capacity, length;
} queue;

void enqueue(queue* q, int e){
	if(q->tail == q->capacity){
		printf("Queue is full!\n");
		fflush(0);
		return;
	}
	++ q->length;
	(q->init)[q->tail++] = e;
}

int dequeue(queue* q , int* out){
	if(q->head != 0 && q->head == q->tail){
		printf("Queue is empty!\n");
		fflush(0);
		return 0;
	}
	-- q->length;
	*out = (q->init)[q->head++];
	return *out;
}
