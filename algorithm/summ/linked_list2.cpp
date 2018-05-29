#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

using namespace linked_list;
using namespace linked_list_test;

namespace linked_list
{
void insert(num ele, node** ref)
{
	node* nn = new node;
	nn->_data = ele;

	if((*ref) == null)
	{
		(*ref) = nn;
	}
	else
	{
		node* ptail = *ref;

		while(ptail->_pnext)
		{
			ptail = ptail->_pnext;
		}

		ptail->_pnext = nn;
	}
}

bool check_if_is_palindrome(node* ref)
{
	if(!ref || !(ref->_pnext)) //if only one node
		return true;

	node* pmid = ref;
	node* pfast = ref;
	node* pslow = ref;

	//find the middle node of the list
	while(pfast)
	{
		pfast = (pfast->_pnext)?pfast->_pnext->_pnext:pfast->_pnext;
		pslow = pslow->_pnext;
	}
	pmid = pslow;

	//reverse the second half of the list
	reverse(&pmid);

	//check if the first half and the second half
	//  have identical value
	node* pfirsthalf = ref;
	node* psecondhalf = pmid;
	while(pfirsthalf && psecondhalf)
	{
		//return false if any node is not identical
		if(pfirsthalf->_data != psecondhalf->_data)
			return false;

		pfirsthalf = pfirsthalf->_pnext;
		psecondhalf = psecondhalf->_pnext;
	}

	return true;
}

};