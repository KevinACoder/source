#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include "defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

typedef int num;
typedef uint32_t uint32;
#define null NULL

namespace linked_list
{
	struct node
	{
		num   _data;
		node* _pnext;

		node():_pnext(NULL){}

		size_t get_length()
		{
			size_t count = 0;
			node* pcur = _pnext;

			while(pcur)
			{
				++count;
				pcur = pcur->_pnext;
			}

			return count;
		}
	};

	node* populate_list();
	void sorted_insert(num ele, node** ref);
	void delete_node(num ele, node** ref); 
	void print_list(node* ref);
	bool check_if_loop_exist(node* ref);
	node* find_the_nth_node_from_tail(node* ref, size_t n);

	node* merge_sorted_list(node* lst1, node* lst2);
};

namespace linked_list_test
{
	using namespace linked_list;

	void test_merge_sorted_list();	
};

#endif