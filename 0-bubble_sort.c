#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int i, j;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
