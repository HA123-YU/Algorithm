#include<stdio.h>
#define NUM_DATA 20

int binary_search(int array[], int n, int key) {
	int low, high, mid;
	int round = 0;
	low = 0;
	high = n - 1;
	//첫번째 라운드
	round++;
	//low가 high보다 같거나 작을때 동안
	while (low <= high) {
		//low , high의 위치를 나타낸다.
		printf("%2d_th round : Search range : [%2d, %2d]\n", round, low, high);
		//mid는 low와 high 위치값의 절반에 위치한다.
		mid = (low + high) / 2;
		//만약 key 값이 mid의 값과 같다면, mid를 리턴해준다.
		//mid 값이 key 값이라는 의미
		if (key == array[mid])
			return mid;
		//만약 key 값이 미드보다 작다면, high는 
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
