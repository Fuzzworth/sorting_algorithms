#include "sort.h"
#include <stdio.h>

/**
 * partition - short description
 *
 * Description: long description
 *
 * @array: argument_1 description
 * @low: argument_2 description
 * @high: argument_2 description
 * @size: argument_2 description
 *
 * Return: return description
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	int pivot = (*array)[high];
	int i = low - 1, j = high + 1, temp;

	while (1)
	{
		do {
			i++;
		} while ((*array)[i] < pivot);

		do {
			j--;
		} while ((*array)[j] > pivot);

		if (i > j)
			return (j);

		temp = (*array)[i];
		(*array)[i] = (*array)[j];
		(*array)[j] = temp;
		print_array(*array, size);
	}
}

/**
 * qS - short description
 *
 * Description: long description
 *
 * @array: argument_1 description
 * @low: argument_2 description
 * @high: argument_2 description
 * @size: argument_2 description
 *
 * Return: return description
 */
void qS(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		qS(array, low, pi, size);
		qS(array, (pi + 1), high, size);
	}
}

/**
 * quick_sort_hoare - short description
 *
 * Description: long description
 *
 * @array: argument_1 description
 * @size: argument_2 description
 *
 * Return: return description
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		qS(&array, 0, (size - 1), size);
}
