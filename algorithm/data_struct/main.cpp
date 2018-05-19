//main.cpp
#include <stdio.h>
#include <stdlib.h>
#include "struct_defines.h"

int main(int argc, char const *argv[])
{
	/* code */
	// singal_linked_list::node* pheader = singal_linked_list::populate_list();
	// //printf("%d\n", pheader->_data);
	// //singal_linked_list::print_list(pheader);
	// //singal_linked_list::delete_node(4, &pheader);
	// singal_linked_list::print_list(pheader);

	// bool bhasloop = singal_linked_list::check_if_loop_exist(pheader);
	// if(bhasloop)
	// 	printf("has loop\n");
	// else
	// 	printf("no loop\n");

	// singal_linked_list::node* pnode = singal_linked_list::find_the_nth_node_from_tail(pheader, 90);
	// if (pnode)
	// {
	// 	/* code */
	// 	printf("%d\n", pnode->_data);
	// }

	//binary tree
	binary_tree::node* proot = null;
	binary_tree::populate_tree(&proot);
	//binary_tree::print_in_level_order(proot);

	//sorted array
	sorted_array::array m_array;
	m_array.insert(2);
	m_array.insert(1);
	m_array.insert(3);
	m_array.insert(5);
	m_array.insert(1);
	m_array.insert(3);
	//m_array.print();
	m_array.print_unique();

	return 0;
}
