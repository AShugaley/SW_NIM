
// hw2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include "sp_nim.h"
#include "main_aux.h"
#define SIZE 32

int isEmpty(int arr[], int len);
void user_move(int heaps[], int numOfHeaps);
void comp_move(int heaps[], int numOfHeaps);
void printHeaps(int arr[], int len);
void printNames(int arr[], int len, int cnt);

int main()
{
	int heaps[32] = { 0 };
	int numOfHeaps = 0;
	int i = 0;
	int cnt = 0;

	printf("Enter the number of heaps:\n");
	scanf("%d", &numOfHeaps);
	if (numOfHeaps < 1 || numOfHeaps>32)
	{
		printf("Error: the number of heaps must be between 1 and 32.\n");
		exit(0);
	}
	printf("Enter the heap sizes:\n");
	while (i < numOfHeaps && scanf("%d", &heaps[i]) == 1)
	{
		if (heaps[i] <= 0)
		{
			printf("Error: the size of heap %d should be positive.\n", i + 1);
			exit(0);
		}
		i++;
	}
	while (1) {
		printNames(heaps, numOfHeaps, ++cnt);
		comp_move(heaps, numOfHeaps);
		if (isEmpty(heaps, numOfHeaps)) {
			printf("Computer wins!\n");
			exit(0);
		}
		printNames(heaps, numOfHeaps, ++cnt);
		printHeaps(heaps, numOfHeaps);
		user_move(heaps, numOfHeaps);
		if (isEmpty(heaps, numOfHeaps)) {
			printf("You win!\n");
			exit(0);
		}
	}
	return 0;
}





