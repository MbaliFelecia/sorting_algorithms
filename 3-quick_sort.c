#include "sort.h"

/**
 * swap - Swaps two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array and returns the pivot index.
 *
 * @array: Array to be sorted.
 * @low: Lower index.
 * @high: Higher index.
 * @size: Size of the array.
 *
 * Return: Pivot index.
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = (low - 1);

	for (ssize_t j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for quick sort.
 *
 * @array: Array to be sorted.
 * @low: Lower index.
 * @high: Higher index.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Applies the quick sort algorithm to an array of integers.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

