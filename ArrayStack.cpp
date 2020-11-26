#include<stdio.h>
#include<stdlib.h>
#include"ArrayStack.h"


//1. 스택을 초기화하는 함수
Array_stack* initStack(Array_stack* pArrayStack, int capacity) {
	int* array;


	//1. 동적 할당 
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
//배열을 확장하는 함수
int* expandStack(Array_stack* arrStack) {
	int* newArray, * oldArray;
	int oldCapacity, newCapacity;

	oldCapacity = arrStack->capacity;
	newCapacity = arrStack->capacity * 2;
	//기존의 스택에 추가로 데이터를 할당한다.
	printf("Expanding Array Stack (Current capacity (%d)->newCapacity(%d)", oldCapacity, newCapacity);
	oldArray = arrStack->stack;
	newArray = (int*)calloc(sizeof(int), newCapacity);
	if (newArray == NULL) {
		printf("Error in meemory allocation for integer array of size(%d)\n", newCapacity);
		exit(-1);
	}
	arrStack->stack = newArray;
	

	//쓰레기 값이 저장되어 있는 추가로 할당된 데이터를 '0' 으로 초기화 시킨다.
	for (int i = 0; i < oldCapacity;i++) {
		newArray[i] = oldArray[i];
	}
	arrStack->capacity = newCapacity;
	free(oldArray);
	return newArray;
	//확장이 완료된 스택을 반환한다.
	
}
//스택을 출력하는 함수
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
//스택이 비었는지, 꽉 차있는지 꽉 차있다면, 확장배열을 호출해야겠다.
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
//스택에 삽입하는 함수
void push(Array_stack* arrStack, int data) {
	//먼저 스택이 꽉 차있는지 확인한다. 
	if (isStackFull(arrStack)) {
		//꽉 차 있다면, 확장한다.
		expandStack(arrStack);
	}
	//확장했다면, top에 1을 더해주고, 
	arrStack->top++;
	//top에 해당하는 부분에 data를 저장한다.
	arrStack->stack[arrStack->top] = data;
}
//스택에서 가장 먼저 빠질 데이터를 찾는 함수
int* top(Array_stack* arrStack) {
	//top을 지정해준다.
	/*
	int *pData = &(arrStack->stack[arrStack->capacity]);
	printf("제일 위에 위치한 데이터는 %2d 입니다.", arrStack->top);
	return pData;
	*/
	if (isStackEmpty(arrStack))
		return NULL;
	int* pData = &(arrStack->stack[arrStack->top]);
	return pData;
}
//스택에서 데이터를 추출하는 함수
int* pop(Array_stack* arrStack) {
	if (isStackEmpty(arrStack)) {
		printf("스택이 텅 비었습니다.");
	}
	int* pData = &(arrStack->stack[arrStack->top]);

	//stack에서 1을 뺀다.
	arrStack->top--;
	return pData;


}