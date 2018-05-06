int binary_search(const int* arr, int low_ix, int high_ix, const int target)
{
	if(high_ix >= low_ix)
	{
		int mid_ix = low_ix + (high_ix - low_ix)/2;

		if(arr[mid_ix] == target)
			return mid_ix;

		if (arr[mid_ix] > target)
			return binary_search(arr, low_ix, mid_ix - 1, target);

		return binary_search(arr, mid_ix + 1, high_ix, target);
	}
	else
	{
		return -1;
	}
}
