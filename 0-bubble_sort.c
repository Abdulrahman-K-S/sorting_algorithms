#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in
 *               ascending order using the Bubble sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, max = size - 1;
	int temp, swapped = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < max; i++)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = temp;
			swapped = 1;
			print_array(array, size);
		}

		if (swapped == 1 && i == max - 1)
			i = -1, swapped = 0, --max;
	}
}
