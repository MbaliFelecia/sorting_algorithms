#include "sort.h"

/**
 * arr_zero_init - Initializes an array with zeros.
 *
 * @array: The array to be initialized.
 * @size: The size of the array.
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_max - Finds the maximum value in the array.
 *
 * @array: The array to find the maximum value from.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	if (size < 2)
		return (0);

	max = array[0]; /* Start from the first index */

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * allocate_count_arrays - Allocates and initializes count and sumPosition arrays.
 *
 * @size: The size of the arrays.
 * @k: The maximum value in the array.
 * @count: Pointer to the count array.
 * @sumPosition: Pointer to the sumPosition array.
 *
 * Return: 0 if successful, -1 on failure.
 */
int allocate_count_arrays(size_t size, int k, int **count, int **sumPosition)
{
	*count = malloc(sizeof(int) * (k + 1));
	if (*count == NULL)
		return (-1);

	arr_zero_init(*count, k + 1);

	*sumPosition = malloc(sizeof(int) * (k + 1));
	if (*sumPosition == NULL)
	{
		free(*count);
		return (-1);
	}

	arr_zero_init(*sumPosition, k + 1);
	(*sumPosition)[0] = (*count)[0];

	return (0);
}

/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 *
 * @array: The initial array.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int k = get_max(array, size);
	int j, *position, *sumPosition, *sorted;
	size_t i;

	if (k == 0)
		return;

	if (allocate_count_arrays(size, k, &position, &sumPosition) == -1)
		return;

	for (i = 0; i < size; i++)
		position[array[i]] += 1; /* Set one to the positions */

	for (j = 1; j < (k + 1); j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position);
	print_array(sumPosition, k + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(sumPosition);
		return;
	}

	arr_zero_init(sorted, size);

	for (i = 0; i < size; i++) /* Get the sorted array */
	{
		sumPosition[array[i]] -= 1;
		sorted[sumPosition[array[i]]] = array[i];
	}
	free(sumPosition);

	for (i = 0; i < size; i++) /* Update the array */
		array[i] = sorted[i];
	free(sorted);
}

