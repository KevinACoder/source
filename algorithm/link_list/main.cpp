//#include "data_struct.h"

#include "stdio.h"
#include "stdlib.h"
#include <new>

#define OK   0
#define NOK -1

struct  node_s_list_int
{
	int _data;
	node_s_list_int* _pnext;
};

enum name
{
	REVERSR_S_LINK_LIST,	
};

static char sInfoBuf[256] = {'\0'};
int reverse_s_link_list(node_s_list_int* arr, int arr_size);

int main(int argc, char const *argv[])
{
	if(argc < 2)
	{
		printf("no enough parameter\n");
		return NOK;
	}

	int nstatus = OK;
	int nwhich_case = atoi(argv[1]);
	switch(nwhich_case)
	{
		case REVERSR_S_LINK_LIST:
		{
			const int num = 10;
			node_s_list_int* arr = new node_s_list_int[num];
			arr[num-1]._data = num-1;
			arr[num-1]._pnext = NULL;
			for(int i = num - 2; i >= 0; --i)
			{
				arr[i]._data = i;
				arr[i]._pnext = arr + (i+1);
			}

			nstatus = reverse_s_link_list(arr, num);
			printf("reverse_s_link_list excuted\n");
		}
	}

	return nstatus;
}

int reverse_s_link_list(node_s_list_int* arr, int arr_size)
{


	return OK;
}
