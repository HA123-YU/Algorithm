#pragma once
#ifndef  ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct {
	int* stack;
	int capacity;
	int top;
}Array_stack;
//1. 스택을 초기화하는 함수
Array_stack* initStack(Array_stack* pArrayStack, int capacity);
//배열을 확장하는 함수
int* expandStack(Array_stack* arrStack);
//스택을 출력하는 함수
void printStack(Array_stack* arrStack);
//스택이 비었는지, 꽉 차있는지 꽉 차있다면, 확장배열을 호출해야겠다.
bool isStackFull(Array_stack* arrStack);
bool isStackEmpty(Array_stack* arrStack);
//스택에 삽입하는 함수
void push(Array_stack* arrStack, int data);
//스택에서 가장 먼저 빠질 데이터를 찾는 함수
int* top(Array_stack* arrStack);
//스택에서 데이터를 추출하는 함수
int * pop(Array_stack* arrStack);
#endif // ! ARRAY_STACK_H
