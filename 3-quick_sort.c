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
	size_t lw, rw;

	lw = 0;
	rw = size - 1;

	partition(array, size, lw, rw);
}

/**
 * partition - partition function
 * @array: array to sort
 * @size: size of the array
 * @left: element on the left
 * @right: element on the right
 * Return: void
 */

void partition(int *array, size_t size, size_t left, size_t right)
{
	size_t i, j, pivot;

	if (left >= right)
	{
		return;
	}

	pivot = right;
	while (array[i] < array[pivot] && i < pivot)
		i++;

	if (i < right)
	{
		pivot = swap(array, size, i, pivot);

		j = right - 1;
		while (i < j)
		{
			if (array[j] < array[pivot])
			{
				swap(array, size, i, j);
				i++;
			}
			j--;
		}
	}
	else
		pivot = i--;

	swap(array, size, pivot, i - 1);

	partition(array, size, left, i - 2);
	partition(array, size, i, right);
}

/**
 * swap - swap function in quicksort
 * @array: array to sort
 * @size: size of the array
 * @idx1: index of element 1
 * @idx2: size of the array
 * Return: an integer type of size_t
 */
size_t swap(int *array, size_t size, size_t idx1, size_t idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;

	print_array(array, size);

	return (idx1);
}
