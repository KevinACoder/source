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
	void insert(num ele, node** ref); //insert in a unsorted way
	void sorted_insert(num ele, node** ref);
	void delete_node(num ele, node** ref); 
	node* delete_node(node* ref, num ele);

	void print_list(node* ref);
	bool check_if_loop_exist(node* ref);
	node* find_the_nth_node_from_tail(node* ref, size_t n);

	node* merge_sorted_list(node* lst1, node* lst2);
	void remove_duplicate_node(node* lst); //remove in unsorted list
	void remove_duplicate_node_aft_sorted(node* lst);

	void reverse(node** ref);
	bool check_if_is_palindrome(node* ref);

	struct snode
	{
		char   _data;
		snode* _pnext;

		snode():_pnext(null){}
		void push_back(char ch);
		char pop_back();
		void print();

	};
};

namespace linked_list_test
{
	using namespace linked_list;

	void test_merge_sorted_list();	
	void test_remove_duplicate_node();
	void test_reverse();
	void test_delete_node();

	void test_list_is_palindrome();

	void test_snode();
};

#endif