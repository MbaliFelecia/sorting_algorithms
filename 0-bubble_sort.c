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
	size_t x, y;
	int swap, tmp;

	if (array == NULL)
		return;
	for (x = 0; x <= size - 1; x++)
	{
		swap = 0;
		for (y = 0; y <= size - x - 1; y++)
		{
			if (array[y + 1] < array[y])
			{
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
				print_array(array, size);
			}
			swap = 1;
		}
		if (swap == 0)
			break;
	}
}
