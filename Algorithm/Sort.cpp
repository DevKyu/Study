#include "Sort.h"

void Sort::InsertionSort(int* arr, int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i--] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void Sort::SelectionSort(int* arr, int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (arr[j] < arr[i])
				Swap(arr[i], arr[j]);
		}
	}
}

void Sort::BubbleSort(int* arr, int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (arr[j] < arr[i])
				Swap(arr[i], arr[j]);
		}
	}
}

void Sort::QuickSort(int* arr, int left, int right)
{
	int pivot = left;
	int i = left, j = right;

	int mid = (left + right) / 2;
	Swap(arr[pivot], arr[mid]);
	
	if (left < right)
	{
		while (i < j)
		{
			while (arr[pivot] > arr[i])
				i++;
			while (arr[pivot] < arr[j])
				j--;

			if (i < j)
				Swap(arr[i], arr[j]);
		}

		Swap(arr[pivot], arr[j]);

		if (left < j)
			QuickSort(arr, left, j-1);
		if (right > j)
			QuickSort(arr, j+1, right);
	}
}