#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: the array
 * @size: thae size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, jMin;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[jMin])
				jMin = j;

		if (jMin != i)
		{
			tmp = array[i];
			array[i] = array[jMin];
			array[jMin] = tmp;

			print_array(array, size);
		}
	}
}
