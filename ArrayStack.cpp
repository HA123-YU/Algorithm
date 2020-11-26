#include<stdio.h>
#include<stdlib.h>
#include"ArrayStack.h"


//1. ������ �ʱ�ȭ�ϴ� �Լ�
Array_stack* initStack(Array_stack* pArrayStack, int capacity) {
	int* array;


	//1. ���� �Ҵ� 
	array = (int*)calloc(sizeof(int), capacity);
	if (array == NULL) {
		printf("Error in memroy allocation for integer array of size(%d)\n",capacity);
		exit;
	}
	pArrayStack->stack = array;
	pArrayStack->capacity = capacity;
	pArrayStack->top = -1;

	return pArrayStack;

}
//�迭�� Ȯ���ϴ� �Լ�
int* expandStack(Array_stack* arrStack) {
	int* newArray, * oldArray;
	int oldCapacity, newCapacity;

	oldCapacity = arrStack->capacity;
	newCapacity = arrStack->capacity * 2;
	//������ ���ÿ� �߰��� �����͸� �Ҵ��Ѵ�.
	printf("Expanding Array Stack (Current capacity (%d)->newCapacity(%d)", oldCapacity, newCapacity);
	oldArray = arrStack->stack;
	newArray = (int*)calloc(sizeof(int), newCapacity);
	if (newArray == NULL) {
		printf("Error in meemory allocation for integer array of size(%d)\n", newCapacity);
		exit(-1);
	}
	arrStack->stack = newArray;
	

	//������ ���� ����Ǿ� �ִ� �߰��� �Ҵ�� �����͸� '0' ���� �ʱ�ȭ ��Ų��.
	for (int i = 0; i < oldCapacity;i++) {
		newArray[i] = oldArray[i];
	}
	arrStack->capacity = newCapacity;
	free(oldArray);
	return newArray;
	//Ȯ���� �Ϸ�� ������ ��ȯ�Ѵ�.
	
}
//������ ����ϴ� �Լ�
void printStack(Array_stack* arrStack) {
	
	int data;

	printf("Elements in stack: ");
	if (isStackEmpty(arrStack))
	{
		printf("Stack is Empty");
	}
	else {
		for (int i = arrStack->top; i >= 0; i--) {
			data = arrStack->stack[i];
			printf("%3d", data);
		}
	}
	printf("\n");
}
//������ �������, �� ���ִ��� �� ���ִٸ�, Ȯ��迭�� ȣ���ؾ߰ڴ�.
bool isStackFull(Array_stack* arrStack) {
	if (arrStack->top == (arrStack->capacity - 1))
		return true;
	else
		return false;
}
bool isStackEmpty(Array_stack* arrStack) {
	if (arrStack->top == -1)
		return true;
	else
		return false;
}
//���ÿ� �����ϴ� �Լ�
void push(Array_stack* arrStack, int data) {
	//���� ������ �� ���ִ��� Ȯ���Ѵ�. 
	if (isStackFull(arrStack)) {
		//�� �� �ִٸ�, Ȯ���Ѵ�.
		expandStack(arrStack);
	}
	//Ȯ���ߴٸ�, top�� 1�� �����ְ�, 
	arrStack->top++;
	//top�� �ش��ϴ� �κп� data�� �����Ѵ�.
	arrStack->stack[arrStack->top] = data;
}
//���ÿ��� ���� ���� ���� �����͸� ã�� �Լ�
int* top(Array_stack* arrStack) {
	//top�� �������ش�.
	/*
	int *pData = &(arrStack->stack[arrStack->capacity]);
	printf("���� ���� ��ġ�� �����ʹ� %2d �Դϴ�.", arrStack->top);
	return pData;
	*/
	if (isStackEmpty(arrStack))
		return NULL;
	int* pData = &(arrStack->stack[arrStack->top]);
	return pData;
}
//���ÿ��� �����͸� �����ϴ� �Լ�
int* pop(Array_stack* arrStack) {
	if (isStackEmpty(arrStack)) {
		printf("������ �� ������ϴ�.");
	}
	int* pData = &(arrStack->stack[arrStack->top]);

	//stack���� 1�� ����.
	arrStack->top--;
	return pData;


}