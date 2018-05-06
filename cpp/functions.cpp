#include <stdio.h>
#include <stdlib.h>

int calculate_angle_of_clock_pointer(int hour, int min);
int find_min_element_in_moved_order_list(int* arr, size_t arr_num);

int main(int argc, const char* argv[])
{
	// if(argc < 3)
	// 	return -1;

	// printf("hour: %s, min: %s \n", argv[1], argv[2]);
	// int angle = calculate_angle_of_clock_pointer(atoi(argv[1]), atoi(argv[2]));
	// printf("angle is %d \n", angle);

	int arr[] = {3, 4, 5, 6, 7, 1, 2};
	int tar = find_min_element_in_moved_order_list(arr, sizeof(arr)/sizeof(arr[0]));
	printf("min value is %d\n", tar);

	return 0;
}

int calculate_angle_of_clock_pointer(int hour, int min)
{
	int abs_angle_of_mp = 360*min/60;
	int abs_angle_of_hp = 360*(hour%12)/12 + 360*(min/60)*(1/12);

	return abs_angle_of_hp - abs_angle_of_mp;
}

int find_min_element_in_moved_order_list(int* arr, size_t arr_num)
{
	int ilow = 0;//arr[0];
	int ihigh = arr_num-1;//arr[arr_num-1];

	if(ilow == ihigh)
		return arr[ilow];

	int imid = (ilow + ihigh)/2;

	if(arr[imid] > arr[ihigh])
	{
		size_t sub_arr_num = ihigh-imid + 1;
		int sub_arr[sub_arr_num];
		for (int i = imid; i <= ihigh; ++i)
		{
			sub_arr[i-imid] = arr[i];
		}
		return find_min_element_in_moved_order_list(sub_arr, sub_arr_num);
	}
	else
	{
		size_t sub_arr_num = imid-ilow + 1;
		int sub_arr[sub_arr_num];
		for (int i = ilow; i <= imid; ++i)
		{
			sub_arr[i-ilow] = arr[i];
		}
		return find_min_element_in_moved_order_list(sub_arr, sub_arr_num);	
	}

}
