#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing elements to be swapped.
 * @first: The index of the first element.
 * @second: The index of the second element.
 */
void swap(int **array, int first, int second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * build_Max_Heap - Builds a max heap from an array.
 * @array: The array to be transformed into a max heap.
 * @end_index: The ending index for partitioning.
 * @start_index: The starting index for sorting.
 * @array_size: The size of the original array (unchanged).
 */
void build_Max_Heap(int *array, int end_index, int start_index, int array_size)
{
	int largest, left, right;

	largest = start_index;
	left = (start_index * 2) + 1;
	right = (start_index * 2) + 2;

	if (left < end_index && array[left] > array[largest])
		largest = left;

	if (right < end_index && array[right] > array[largest])
		largest = right;

	if (largest != start_index)
	{
		swap(&array, start_index, largest);
		print_array(array, array_size);
		build_Max_Heap(array, end_index, largest, array_size);
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int start_index, i;

	if (!array || size < 2)
		return;

	start_index = ((int)size - 1) / 2;

	/* Build max heap */
	for (i = start_index; i >= 0; i--)
	{
		build_Max_Heap(array, size, i, size);
	}

	/* Destroy max heap and print sorted array */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array, 0, i);
		print_array(array, size);
		build_Max_Heap(array, i, 0, size);
	}
}

