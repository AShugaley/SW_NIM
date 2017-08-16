
#include <stdio.h>
void printHeaps(int arr[], int len);
void printNames(int arr[], int len, int cnt);

void printHeaps(int arr[], int len) {
	int max_val = -1;
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
		if (arr[i] > max_val)
			max_val = arr[i];

	for (i = max_val; i > 0; i--) {
		for (j = 0; j < len; j++) {
			if (arr[j] >= i)
				printf("%c", '*');
			else
				printf("%c", ' ');
			if (j == len - 1)
				printf("%c", '\n');
			else
				printf("%c", '\t');
		}
	}



}
void printNames(int arr[], int len, int cnt) {
	int i = 0;
	printf("In turn %d heap sizes are:", cnt);
	for (i = 1; i <= len; i++) {
		printf(" h%d=%d", i, arr[i - 1]);
	}
	printf(".\n");
}
/////