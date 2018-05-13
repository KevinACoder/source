//main.cpp
#include <stdio.h>
#include <stdlib.h>
#include "struct_defines.h"

int main(int argc, char const *argv[])
{
	/* code */
	singal_linked_list::node* pheader = singal_linked_list::populate_list();
	//printf("%d\n", pheader->_data);
	singal_linked_list::print_list(pheader);
	singal_linked_list::delete_node(3, &pheader);
	singal_linked_list::print_list(pheader);

	return 0;
}
