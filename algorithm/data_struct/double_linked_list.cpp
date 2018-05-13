//double_linked_list.cpp
#include "struct_defines.h"

namespace singal_linked_list
{
	node* populate_list()
	{
		/*node* phead = new node;
		phead->_data = 1;
		phead->_pnext = NULL;*/

		node* phead = NULL;
		sorted_insert(0, &phead);
		//printf("add %p\n", phead);
		sorted_insert(-1, &phead);
		//printf("add %p\n", phead);
		sorted_insert(4, &phead);
		sorted_insert(3, &phead);
		sorted_insert(100, &phead);
		sorted_insert(34, &phead);

		return phead;
	}

	void sorted_insert(num ele, node** ref)
	{
		if(!*ref) //no header , create one
		{
			*ref = new node;
			(*ref)->_data = ele;
		}
		else if(ele < (*ref)->_data) //insert before head
		{
			//printf("insert bef\n");
			node* nn = new node;
			nn->_data = ele;
			nn->_pnext = (*ref);
			//ref = &nn;
			*ref = nn; //ref = &nn;
		}
		else
		{
			node* pcurr = *ref;
			node* pprev = NULL;

			while(pcurr)
			{
				if(pcurr->_data >= ele) //insert before node that just greater than ele
				{
					break;
				}

				pprev = pcurr;
				pcurr = pcurr->_pnext;
			}

			node* nn = new node;
			nn->_data = ele;
			if(pcurr == NULL) //insert tail
			{
				pprev->_pnext = nn;
				nn->_pnext = NULL;
			}
			else //insert middle
			{
				nn->_pnext = pcurr;
				pprev->_pnext = nn;
			}

		}

		return;
	}

	void print_list(node* ref)
	{
		if(ref == NULL) return;
		node* pnode = ref;
		while(pnode)
		{
			printf("%d\n", pnode->_data);
			pnode = pnode->_pnext;
		}

	}

	void delete_node(num ele, node** ref)
	{
		if(!*ref) return;

		if((*ref)->_data == ele)
		{
			node* phead = (*ref)->_pnext;
			delete *ref;
			*ref = phead;
			return;
		}

		node* pcurr;
		node* pprev;

		while(pcurr)
		{
			if(pcurr->_data == ele)
				break;

			pprev = pcurr;
			pcurr = pcurr->_pnext;
		}

		if(pcurr)
		{
			printf("delete\n");
			pprev->_pnext = pcurr->_pnext;
			delete pcurr;
		}
		else
		{
			pprev->_pnext = NULL;
		}

		return;
	}
};
