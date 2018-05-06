#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include "AlgorithmConfig.h"

//extern int binary_search(int* arr, size_t arr_num);
extern int binary_search(const int* arr, int low_ix, int high_ix, const int target);

int main(int argc, char* argv[])
{
	fprintf(stdout, "%s VERSION %d.%d \n", argv[0], Algorithm_VERSION_MAJOR,
	 Algorithm_VERSION_MINOR);
	if(argc < 2)
	{
		printf("no enough parameter\n");
		return -1;
	}

	printf("parameter %s\n", argv[1]);
	int arr[] = {1, 2, 3, 5, 6, 7, 8};
	int low = 0;
	int high = sizeof(arr)/sizeof(arr[0])-1;
	int target = atoi(argv[1]);
	int ret = binary_search(arr, low, high, target);
	printf("target %d at ret %d \n",target, ret); 
	return 0;
}
 
