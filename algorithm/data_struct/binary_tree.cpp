#include "struct_defines.h"

namespace binary_tree
{
	node* create_node(num ele)
	{
		node* pnode = new node;
		pnode->_data = ele;
		return pnode;
	}

	void insert_node(node** ref, num ele)
	{
		if((*ref) == null)
		{
			*ref = create_node(ele);
			return;
		}
		if(ele >= (*ref)->_data)
		{
			return insert_node(&((*ref)->_pright), ele);
		}
		else
		{
			return insert_node(&((*ref)->_pleft), ele); 
		}
	}

	void populate_tree(node** ref)
	{
		insert_node(ref, 3);
		insert_node(ref, 6);
		insert_node(ref, 1);
		insert_node(ref, 8);
		return;
	}

	size_t height(node* ref)
	{
		if(ref == null)
			return 0;
		else
		{
			size_t lheight = height(ref->_pleft);
			size_t rheight = height(ref->_pright);

			if(lheight > rheight)
				return lheight+1;
			else
				return rheight+1;
		}
	}

	void print_in_level_order(node* ref)
	{
		printf("START\n");
		size_t h = height(ref);
		for(int i = 1; i <= h; i++)
			print_given_level(ref, i);

		printf("END\n");
	}

	void print_given_level(node* ref, size_t level)
	{
		if (ref == null || level == 0)
		{
			return;
		}
		else if(level == 1)
		{
			printf("%d\n", ref->_data);
		}
		else
		{
			print_given_level(ref->_pleft, level-1);
			print_given_level(ref->_pright, level-1);
		}
	}
};