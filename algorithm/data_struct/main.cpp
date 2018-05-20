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
	//m_array.print_unique();

	//2-d array
	sorted_array::array_2d m_array_2d;
	m_array_2d.populate_array();
	//m_array_2d.print();

	//string
	// sorted_array::string str("sdcfFRTo");
	// str.print();
	// printf("%ld\n", str.atoi());

	// //str.itoa(123, 0);
	// str.to_upper();
	// str.print();

	// str.itoa(1234);
	// str.print();

	// str.reverse();
	// str.print();

	sorted_array::string str("hello programming world");
	str.print();
	//str.reverse_words();
	//str.print();

	int val = 0x01;
	bit_operations::set_bit(3, &val);
	printf("val bef set %d, val aft set %d\n", 0x01, val);

	int num = 49;
	printf("%d divide 7 is %d\n", num, bit_operations::divide_7(&num));

	return 0;
}
