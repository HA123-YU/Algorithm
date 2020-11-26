#include<stdio.h>
#include<stdlib.h>
#include"ArrayStack.h"
#define INIT_STACK_CAPACITY 1

void main() {
	Array_stack* pIntArrayStack;
	int* pD;

	printf("Initializing integer stack of capacity(%d)\n",INIT_STACK_CAPACITY);
	pIntArrayStack = (Array_stack*)calloc(sizeof(Array_stack), 1);
	pIntArrayStack = initStack(pIntArrayStack, INIT_STACK_CAPACITY);
	printStack(pIntArrayStack);
	printf("\n Pushing data into integer stack : \n");
	for (int i = 0; i < 10; i++) {
		push(pIntArrayStack,i);
		printStack(pIntArrayStack);

	}
	printf("\nPoping data from integer stack : \n");
	for (int i = 0; i < 10; i++) {
		pD = top(pIntArrayStack);
		if (pD != NULL)
			printf("current top is = %3d", *pD);
		pD = pop(pIntArrayStack);
		if (pD != NULL)
			printf("==> poped data = %3d\n", *pD);
		printStack(pIntArrayStack);
	}
}