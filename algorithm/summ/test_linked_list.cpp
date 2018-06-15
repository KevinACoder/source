#include "linked_list.h"

using namespace linked_list;
using namespace linked_list_test;

namespace linked_list_test
{
	using namespace linked_list;

	void test_list_is_palindrome()
	{
		printf("rountie: <test_list_is_palindrome>\n");
		node* plst = null;
		insert(1, &plst);
		insert(2, &plst);
		insert(2, &plst);	
		insert(1, &plst);
		print_list(plst);	

		if(check_if_is_palindrome(plst))
			printf("is palindrome\n");
		else
			printf("is not palindrome\n");	
	}

	void test_delete_node()
	{
		printf("rountie: <test_delete_node>\n");
		node* plst = null;
		sorted_insert(1, &plst);
		sorted_insert(1, &plst);
		//sorted_insert(1, &plst);	
		print_list(plst);

		plst = delete_node(plst, 1);	
		print_list(plst);
	}

	void test_reverse()
	{
		printf("rountie: <test_reverse>\n");
		node* plst = null;
		sorted_insert(1, &plst);
		sorted_insert(2, &plst);
		sorted_insert(4, &plst);	
		print_list(plst);

		reverse(&plst);
		print_list(plst);
	}

	void test_merge_sorted_list()
	{
		printf("rountie: <test_merge_sorted_list>\n");
		node* plst1 = null;
		node* plst2 = null;

		sorted_insert(1, &plst1);
		sorted_insert(2, &plst1);
		sorted_insert(4, &plst1);
		print_list(plst1);

		sorted_insert(1, &plst2);
		sorted_insert(3, &plst2);
		sorted_insert(4, &plst2);
		print_list(plst2);

		node* psum = merge_sorted_list(plst1, plst2);
		print_list(psum);
	}

	void test_remove_duplicate_node()
	{
		printf("rountie: <test_remove_duplicate_node>\n");
		node* plst1 = null;
		node* plst2 = null;

		sorted_insert(1, &plst1);
		sorted_insert(2, &plst1);
		sorted_insert(4, &plst1);
		print_list(plst1);

		sorted_insert(1, &plst2);
		sorted_insert(3, &plst2);
		sorted_insert(4, &plst2);
		print_list(plst2);

		node* psum = merge_sorted_list(plst1, plst2);
		print_list(psum);

		//remove_duplicate_node(psum);
		remove_duplicate_node_aft_sorted(psum);
		print_list(psum);
	}

	void test_snode()
	{
		snode* pnode = new snode;
		pnode->_data = '{';
		pnode->push_back('a');
		pnode->push_back('}');
		pnode->print();
	}

	void test_add_two_list_of_numbers()
	{
		node* num1 = null;
		node* num2 = null;

		insert(7, &num1);
		insert(2, &num1);
		insert(4, &num1);
		insert(3, &num1);

		insert(5, &num2);
		insert(6, &num2);
		insert(4, &num2);

		node* num_sum = add_two_list_of_numbers(num1, num2);
		print_list(num_sum);
	}

	void test_partition()
	{
		list_node* lst = null;
		insert_back(1, &lst);
		insert_back(3, &lst);
		insert_back(5, &lst);
		insert_back(6, &lst);
		insert_back(2, &lst);
		list_node* res = partition(lst, 3);
		print_list(res);
	}
};