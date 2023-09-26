#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array.
 * @item1: The index of the first element.
 * @item2: The index of the second element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition sorting scheme.
 * @array: The array.
 * @first: The index of the first element.
 * @last: The index of the last element.
 * @size: The size of the array.
 * Return: The position of the last element sorted.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * qs - Implements the Quicksort algorithm.
 * @array: The array.
 * @first: The index of the first element.
 * @last: The index of the last element.
 * @size: The size of the array.
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Initiates the Quicksort algorithm.
 * @array: The array.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

