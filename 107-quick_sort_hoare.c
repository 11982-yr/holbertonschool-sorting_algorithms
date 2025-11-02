#include <stdio.h>

/**
 * swap - swaps the values of two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - partitions an array using Hoare scheme
 * @arr: the array to partition
 * @low: starting index
 * @high: ending index
 * Return: the partition index
 */
int hoare_partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			return (j);

		swap(&arr[i], &arr[j]);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick Sort
 * @arr: the array to sort
 * @low: starting index
 * @high: ending index
 */
void quick_sort(int arr[], int low, int high)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(arr, low, high);
		quick_sort(arr, low, p);
		quick_sort(arr, p + 1, high);
	}
}

/**
 * main - entry point, demonstrates quick sort
 * Return: 0
 */
int main(void)
{
	int arr[20] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
		       95, 31, 20, 22, 98, 39, 92, 41, 62, 1};
	int n = 20;
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf("\n");

	quick_sort(arr, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf("\n");

	return (0);
}
