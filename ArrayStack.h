#pragma once
#ifndef  ARRAY_STACK_H
#define ARRAY_STACK_H

typedef struct {
	int* stack;
	int capacity;
	int top;
}Array_stack;
//1. ������ �ʱ�ȭ�ϴ� �Լ�
Array_stack* initStack(Array_stack* pArrayStack, int capacity);
//�迭�� Ȯ���ϴ� �Լ�
int* expandStack(Array_stack* arrStack);
//������ ����ϴ� �Լ�
void printStack(Array_stack* arrStack);
//������ �������, �� ���ִ��� �� ���ִٸ�, Ȯ��迭�� ȣ���ؾ߰ڴ�.
bool isStackFull(Array_stack* arrStack);
bool isStackEmpty(Array_stack* arrStack);
//���ÿ� �����ϴ� �Լ�
void push(Array_stack* arrStack, int data);
//���ÿ��� ���� ���� ���� �����͸� ã�� �Լ�
int* top(Array_stack* arrStack);
//���ÿ��� �����͸� �����ϴ� �Լ�
int * pop(Array_stack* arrStack);
#endif // ! ARRAY_STACK_H
