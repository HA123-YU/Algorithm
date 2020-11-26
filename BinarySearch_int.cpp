#include<stdio.h>
#define NUM_DATA 20

int binary_search(int array[], int n, int key) {
	int low, high, mid;
	int round = 0;
	low = 0;
	high = n - 1;
	//ù��° ����
	round++;
	//low�� high���� ���ų� ������ ����
	while (low <= high) {
		//low , high�� ��ġ�� ��Ÿ����.
		printf("%2d_th round : Search range : [%2d, %2d]\n", round, low, high);
		//mid�� low�� high ��ġ���� ���ݿ� ��ġ�Ѵ�.
		mid = (low + high) / 2;
		//���� key ���� mid�� ���� ���ٸ�, mid�� �������ش�.
		//mid ���� key ���̶�� �ǹ�
		if (key == array[mid])
			return mid;
		//���� key ���� �̵庸�� �۴ٸ�, high�� 
		else if (key < array[mid])
			high = mid - 1;
		else
			low = mid + 1;
		round++;
	}
	return -1;
}
void printArray(int array[], int size, int line_size) {
	for (int i = 0, count = 0; i < size; i++) {
		printf("%3d", array[i]);
		count++;
		if (count % line_size == 0)
			printf("\n");
	}
	printf("\n");
}
int main() {
	int key_to_search;
	int pos;
	int data_array[NUM_DATA] = {
		0,3,12,26,37,40,43,44,45,46,54,56,59,63,66,75,82,89,94,97
	};
	printf("Data array: \n");
	printArray(data_array, NUM_DATA, 20);
	
	while (1) {
		
		printf("Input a positive key number to search(-1 to exit) : ");
		scanf("%d", &key_to_search);
		if (key_to_search < 0) 
			break;
		printf("Searching key (%d) from array of %d data...\n", key_to_search, NUM_DATA);
		pos = binary_search(data_array, NUM_DATA, key_to_search);
			if (pos != -1)
				printf("The key(%2d) was found at position [%2d]\n", key_to_search, pos);
			else
				printf("The key(%2d) was not found from the array\n", key_to_search);

		}
	}
