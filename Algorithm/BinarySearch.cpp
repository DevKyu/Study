int BinarySearch(int *arr, int len, int FindData)
{
	int left = 0, mid = 0, right = len - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == FindData)
			return mid;
		else
		{
			if (FindData < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return -1;
}

int BinarySerach_recursive(int *arr, int left, int right, int FindData)
{
	int mid;
	if (left > right)
		return -1;
	mid = (left + right) / 2;

	if (arr[mid] == FindData)
		return mid;
	else if (FindData < arr[mid])
		return BinarySerach_recursive(arr, left, mid - 1, FindData);
	else
		return BinarySerach_recursive(arr, mid + 1, right, FindData);
}