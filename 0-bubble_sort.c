#include "sort.h"

/**
 * bubble_sort - function that sorts an array of
 * integers in ascending order using
 * Bubnle sort algorithm
 *
 * @array: input array
 * @size: size of the array
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, i;
	int swap, tmp;

	if (array == NULL)
		return;
	for (x = size; x > 0; x--)
	{
		swap = 0;

		for (i = 0; i < x - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;

				swap = 1;

				print_array(array, size);
			}
		}

		if (swap == 0)
			break;
	}
}
