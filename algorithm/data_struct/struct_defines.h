#ifndef STRUCT_DEFINES
#define STRUCT_DEFINES	

#include <stdio.h>
#include <stdlib.h>

typedef int num;

//struct_defines.h
namespace singal_linked_list
{
	struct node
	{
		num   _data;
		node* _pnext;

		node():_pnext(NULL){}
	};

	node* populate_list();
	void sorted_insert(num ele, node** ref);
	void delete_node(num ele, node** ref);
	void print_list(node* ref);
};

namespace double_linked_list
{
	struct node
	{
		num   _data;
		node* _pnext;
		node* _pprev;

		node():_pprev(NULL),_pnext(NULL){}
	};
};


#endif
