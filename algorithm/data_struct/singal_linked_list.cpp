//singal_linked_list.cpp
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
		sorted_insert(-1, &phead);
		sorted_insert(4, &phead);
		sorted_insert(3, &phead);
		//node* ploops = phead;
		sorted_insert(100, &phead);
		sorted_insert(34, &phead);
		//phead->_pnext = ploops; //make a loop for test

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
		printf("START\n");
		node* pnode = ref;
		while(pnode)
		{
			printf("%d\n", pnode->_data);
			pnode = pnode->_pnext;
		}
		printf("END\n");
	}

	void delete_node(num ele, node** ref)
	{
		if(!*ref) return; //exit if input list is null

		if((*ref)->_data == ele) //if deletion target is header
		{
			node* phead = (*ref)->_pnext;
			delete *ref;
			*ref = phead;
			return;
		}

		node* pcurr = *ref;
		node* pprev = null;

		while(pcurr) //try to find deletion target by value
		{
			if(pcurr->_data == ele)
			{
				//printf("founded\n");
				break;
			}

			pprev = pcurr;
			pcurr = pcurr->_pnext;
		}

		if(pcurr) //if target was found, delete it
		{
			printf("delete\n");
			pprev->_pnext = pcurr->_pnext;
			delete pcurr;
		}
		else //if not found, let it go
		{
			pprev->_pnext = NULL;
		}

		return;
	}

	bool check_if_loop_exist(node* ref)
	{
		//if list length less than 2, no chance to have loop
		if(ref == null || ref->_pnext == null)
			return false;

		//two pointer move with step 1 and step 2, if one pointer hit tail, 
		// end moving, if pointer 1 == pointer 2, exist loop
		node* pstep1 = ref;
		node* pstep2 = ref;

		do
		{
			pstep1 = pstep1->_pnext;
			pstep2 = pstep2->_pnext->_pnext;

			if(pstep1 == pstep2 && pstep1 != null)
				return true;

		}while(pstep2 != null && pstep1 != null && pstep1->_pnext != null &&
			pstep2->_pnext->_pnext != null);

		return false;
	}

	node* find_the_nth_node_from_tail(node* ref, size_t n)
	{
		node* pfirst = ref;
		node* psecond = ref;

		size_t count = 0;
		while(psecond)
		{
			if(count >= n)
				pfirst = pfirst->_pnext;

			psecond = psecond->_pnext;
			++count;
		}

		return pfirst;
	}
};
