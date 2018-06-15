#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <stack>

using namespace linked_list;
using namespace linked_list_test;
using std::map;
using std::stack;

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

typedef map<node*, int> mapNodeOccurance;
node* find_intersection_of_two_linked_list(node* lst1, node* lst2)
{
	mapNodeOccurance mpNodeCount;
	node* p1 = lst1; int len1 = 0;
	node* p2 = lst2; int len2 = 0;

	while(p1 != null)
	{
		++mpNodeCount[p1];
		p1 = p1->_pnext;
		++len1;
	}
	while(p2 != null)
	{
		++mpNodeCount[p2];
		p2 = p2->_pnext;
		++len2;
	}

	if(len1 > len2)
	{
		p1 = lst1;
		while(p1 != null)
		{
			if(mpNodeCount[p1] > 1)
				return p1;

			p1 = p1->_pnext;
		}
	}
	else
	{
		p2 = lst2;
		while(p2 != null)
		{
			if(mpNodeCount[p2] > 1)
				return p2;
			
			p2 = p2->_pnext;
		}
	}

	return null;
}

typedef stack<num> node_stack;
node* add_two_list_of_numbers(node* num1, node* num2)
{
	node_stack stack1, stack2;
	
	node* p1 = num1;
	node* p2 = num2;
	node* pnew_num = null;

	while(p1 != null)
	{
		stack1.push(p1->_data);
		p1 = p1->_pnext;
	}

	while(p2 != null)
	{
		stack2.push(p2->_data);
		p2 = p2->_pnext;
	}

	int carry = 0;
	while(!stack1.empty() || !stack2.empty())
	{
		int count1 = 0, count2 = 0, sum = 0;
		if(!stack1.empty())
		{
			count1 = stack1.top();
			stack1.pop();
		}

		if(!stack2.empty())
		{
			count2 = stack2.top();
			stack2.pop();
		}

		sum = count1 + count2 + carry;
		insert_head(sum%10, &pnew_num);
		carry = sum/10;
	}

	if(carry > 0)
		insert_head(carry, &pnew_num);

	return pnew_num;
}

void insert_head(num ele, node** ref)
{
	node* nn = new node();
	nn->_data = ele;
	nn->_pnext = *ref;
	*ref = nn;
}

void insert_back(int ele, list_node** ref)
{
	list_node* nn = new list_node(ele);

	if(*ref == null)
	{
		*ref = nn;
	}
	else
	{
		list_node* ptail = *ref;
		while(ptail->next != null)
		{
			ptail = ptail->next;
		}

		ptail->next = nn;
	}

	return;
}

void insert_front(int ele, list_node** ref)
{
	list_node* nn = new list_node(ele);
	nn->next = *ref;
	return;
}

list_node* partition(list_node* head, int x)
{
	list_node* psmallerlst = null;
	list_node* pequallst = null;
	list_node* pgreaterlst = null;
	list_node* psumlst = null;

	list_node* ptmp = head;
	int ix = 0;
	while(ix < x)
	{
		++ix;
		ptmp = ptmp->next;
	}
	int pivot = ptmp->val;

	ptmp = head;
	while(ptmp != null)
	{
		int val = ptmp->val;
		if(val < pivot)
		{
			insert_back(val, &psmallerlst);
		}
		else if(val == pivot)
		{
			insert_back(val, &pequallst);
		}
		else if(val > pivot)
		{
			insert_back(val, &pgreaterlst);
		}

		ptmp = ptmp->next;
	}

	ptmp = null;
	if(psmallerlst)
	{
		psumlst = psmallerlst;
		ptmp = psmallerlst;
		while(ptmp->next) 
			ptmp = ptmp->next;
	}

	if(pequallst)
	{
		if(!psumlst)psumlst = pequallst;
		if(ptmp)
			ptmp->next = pequallst;
		else
			ptmp = pequallst;

		while(ptmp->next) 
			ptmp = ptmp->next;
	}

	if(pgreaterlst)
	{
		if(!psumlst)psumlst = pgreaterlst;
		if(ptmp)
			ptmp->next = pgreaterlst;
		else
			ptmp = pgreaterlst;
		
		while(ptmp->next) 
			ptmp = ptmp->next;
	}

	return psumlst;
}

void print_list(list_node* head)
{
	while(head != null)
	{
		printf("[%d]\n", head->val);
		head = head->next;
	}
	return;
}

};