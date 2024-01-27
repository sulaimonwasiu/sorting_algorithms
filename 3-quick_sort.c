#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int end;

	end = size - 1;
	quicksort(array, 0, end, size);
}

/**
 * quicksort - main quick sort
 * @array: array to sort
 * @start: index start
 * @end: index end
 * @size: size of the array
 * Return: void
 */
void quicksort(int *array, int start, int end, size_t size)
{
	if (start < end)
	{
		int partitionIndex;

		partitionIndex = partition(array, start, end, size);
		quicksort(array, start, partitionIndex - 1, size);
		quicksort(array, partitionIndex + 1, end, size);
	}
}
/**
 * partition - partition function
 * @array: array to sort
 * @start: index start
 * @end: index end
 * @size: size of the array
 * Return: void
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int partitionIndex = start;
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(&array[partitionIndex], &array[end]);
	print_array(array, size);
	return (partitionIndex);
}

/**
 * swap - swap function in quicksort
 * @idx1: item 1
 * @idx2: item 2
 * Return: void
 */
void swap(int *idx1, int *idx2)
{
	int temp = *idx1;

	*idx1 = *idx2;
	*idx2 = temp;
}
