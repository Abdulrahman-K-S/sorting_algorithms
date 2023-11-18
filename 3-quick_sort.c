#include "sort.h"

/**
 * partition - A function that divides the array into two partitons
 *
 * @array: The array to be divided.
 * @lo: The lowest index in the partition.
 * @hi: The highest index in the partition.
 * @size: The size of the array.
 *
 * Return: The index of the partition.
*/
int partition(int *array, int lo, int hi, size_t size)
{
	int i = lo, j;
	int pivot = array[hi];
	int temp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (temp != array[i])
				print_array(array, size);
			i++;
		}
	}

	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;

	if (temp != array[i])
		print_array(array, size);

	return (i);
}

/**
 * quick_sort_rec - A recursive function of the quick sort function.
 *
 * @array: The array to be sorted.
 * @lo: The lowest index in the array.
 * @hi: The highest index in the array.
 * @size: The size of the array.
 *
 * Return: Nothing
*/
void quick_sort_rec(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, lo, hi, size);

	quick_sort_rec(array, lo, p - 1, size);
	quick_sort_rec(array, p + 1, hi, size);
}

/**
 * quick_sort - A function that sorts an array of integers in ascending
 *              order using the Quick sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
