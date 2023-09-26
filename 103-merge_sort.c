#include "sort.h"

/**
 * print_parse - Prints the values in an array.
 * @array: The array to be printed.
 * @text: The text to be printed alongside values.
 * @low: The lower bound.
 * @high: The upper bound.
 */
void print_parse(int *array, const char *text, size_t low, size_t high)
{
	size_t i;
	char *separator = "";

	printf("[%s]: ", text);
	for (i = low; i <= high; i++)
	{
		printf("%s%d", separator, array[i]);
		separator = ", ";
	}
	printf("\n");
}

/**
 * join_parse - Joins and sorts the values in the array being parsed.
 * @arr: The array to be sorted.
 * @low: The starting index of the array.
 * @high: The ending index of the array.
 * @mid: The midpoint of the split array.
 * @copy: The array to store sorted values.
 */
void join_parse(int *arr, size_t low, size_t high, size_t mid, int *copy)
{
	size_t hStart = mid + 1, newIndex, lStart = low, i;

	printf("Merging...\n");
	print_parse(arr, "left", low, mid);
	print_parse(arr, "right", mid + 1, high);

	for (newIndex = low; newIndex <= high; newIndex++)  /* Fill sorted values. */
	{
		if ((lStart <= mid && arr[lStart] <= arr[hStart]) || hStart > high)
			copy[newIndex] = arr[lStart++];
		else
			copy[newIndex] = arr[hStart++];
	}

	for (i = low; i <= high; i++)   /* Update the initial array with the sorted array. */
		arr[i] = copy[i];

	print_parse(arr, "Done", low, high);
}

/**
 * parser - Recursively performs merge sort and sorts the given array.
 * @array: The array to be sorted.
 * @lb: The lower bound.
 * @ub: The upper bound.
 * @copy: The array to store sorted values.
 */
void parser(int *array, size_t lb, size_t ub, int *copy)
{
	size_t mid;

	if (lb < ub)
	{
		mid = (ub + lb - 1) / 2;

		parser(array, lb, mid, copy);
		parser(array, mid + 1, ub, copy);

		join_parse(array, lb, ub, mid, copy);
	}
}

/**
 * merge_sort - Applies the merge sort algorithm to sort an array of integers.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *clone;

	if (!array || size < 2)   /* Only one value or less in the array. */
		return;

	clone = malloc(sizeof(int) * size);
	if (!clone)
		return;

	parser(array, 0, size - 1, clone);
	free(clone);
}

