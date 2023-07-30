#include "sort.h"

/**
 * getMax - get maximum
 *
 * @array: array
 * @size: n
 *
 * Return: max
 */
int getMax(int *array, size_t size)
{
	int max;
	size_t i;

	max = *array;
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countingSort - get maximum
 *
 * @array: array
 * @size: size
 * @place: place
 *
 * Return: void
 */
void countingSort(int *array, size_t size, int place)
{
	int *output, *count, max, j;
	size_t i;

	max = (array[0] / place) % 10;
	output = malloc(sizeof(int) * (size + 1));
	if (output == NULL)
		return;
	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (j = 0; j < max; ++j)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = 0; i < size; i++)
	{
		output[count[(array[size - i - 1] / place) % 10] - 1] = array[size - 1 - i];
		count[(array[size - 1 - i] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	print_array(array, size);
	free(output);
	free(count);
	count = NULL;
	output = NULL;
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 * @array: an array of integers
 * @size: size of the array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, place;

	if (size > 1)
	{
		max = getMax(array, size);

		for (place = 1; max / place > 0; place *= 10)
		{
			countingSort(array, size, place);
		}
	}
}
