#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

using namespace linked_list;
using namespace linked_list_test;

int main(int argc, char const *argv[])
{
	/* code */
	printf("linked_list\n");
	test_merge_sorted_list();
	return 0;
}

namespace linked_list_test
{
	using namespace linked_list;

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
};

namespace linked_list
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

	node* merge_sorted_list(node* lst1, node* lst2)
	{
		node* plst = null;

		if(lst1 == null)
		{
			return lst2;
		}
		else if(lst2 == null)
		{
			return lst1;
		}
		else
		{
			node* p1 = lst1;
			node* p2 = lst2;

			if(p1->_data < p2->_data) //p1, p2 both are not null
			{
				plst = p1;
				p1 = p1->_pnext;
			}
			else
			{
				plst = p2;
				p2 = p2->_pnext;
			}
			//printf("create head\n");

			node* pcurr = plst;

			while(true)
			{
				//printf("round\n");
				if(p1 == null && p2 == null) //merge finished
					break;

				if(p1 == null && p2 != null) //p1 finished
				{
					pcurr->_pnext = p2;
					pcurr = pcurr->_pnext;
					p2 = p2->_pnext;
				}
				else if(p1 != null && p2 == null) //p2 finished
				{
					pcurr->_pnext = p1;
					pcurr = pcurr->_pnext;
					p1 = p1->_pnext;
				}
				else //p1 and p2 not finished yet
				{
					if(p1 && p1->_data < p2->_data)
					{
						pcurr->_pnext = p1;
						pcurr = pcurr->_pnext;
						p1= p1->_pnext;
					}
					else
					{
						pcurr->_pnext = p2;
						pcurr = pcurr->_pnext;
						p2 = p2->_pnext;
					}
				}
			}

			return plst;
		}
	}
};