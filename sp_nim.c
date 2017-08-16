
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main_aux.h"

int isEmpty(int arr[], int len);
void user_move(int heaps[], int numOfHeaps);
void comp_move(int heaps[], int len);

int isEmpty(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] != 0)
			return 0;
	}
	return 1;
}

void user_move(int heaps[], int numOfHeaps) {
	int userWhichHeap = 0;
	int userToTake = 0;
	printf("Your turn: please enter the heap index and the number of removed objects.\n");
	while (1) {
		scanf("%d %d", &userWhichHeap, &userToTake);
		if ((userWhichHeap < 1) || (userWhichHeap - 1 >= numOfHeaps) || (userToTake < 1) || (heaps[userWhichHeap - 1] < userToTake))
			printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
		else
			break;
	}
	printf("You take %d objects from heap %d.\n", userToTake, userWhichHeap);
	heaps[userWhichHeap - 1] -= userToTake;
}

void comp_move(int heaps[], int len)
{
	int i = 0;
	int s_tNim = 0;
	int numToTake = 0;
	int heapToTake = 0;
	int nimSum = 0;

	for (i = 0; i < len; i++)
	{
		s_tNim ^= (heaps)[i];
	}
	if (s_tNim == 0)
	{
		for (i = 0; i < len; i++)
		{
			if (heaps[i] > 0)
			{
				heapToTake = i;
				break;
			}
		}

		heaps[heapToTake]--;
		numToTake = 1;
	}

	else
	{
		for (i = 0; i < len; i++)
		{
			nimSum = (heaps)[i] ^ s_tNim;
			if (nimSum < (heaps)[i])
			{
				heapToTake = i;
				numToTake = (heaps)[i] - nimSum;
				(heaps)[i] = nimSum;
				break;
			}
		}
		

	}

	printf("Computer takes %d objects from heap %d.\n", numToTake, heapToTake + 1);

}