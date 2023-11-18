#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in
 *                  ascending order using the Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
