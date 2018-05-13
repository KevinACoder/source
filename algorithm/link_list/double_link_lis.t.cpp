/*Ascedant double linked list*/
#include <stdio.h>
#include <stdlib.h>

#define null NULL

struct node
{
	int _data;
	struct node* _pnext;
	struct node* _pprev;

	node():_pprev(null),_pnext(null){}
};

void reverse_dll(node** ref);
void print_dll(node* ref);
void reverse_print_dll(node* ref);
void insert_element(int ele, node** ref);
void sorted_insert(node* ele, node** ref);

int main(int argc, char const *argv[])
{
	node* plist_header = new node; //create header
	plist_header->_data = 0;
	plist_header->_pprev = null;

	node* pnode = plist_header;
	node* pnext_node = null;
	const int num = 10;
	for(int i = 1; i < num; ++i)
	{
		pnext_node = new node;
		pnext_node->_data = i;
		pnode->_pnext = pnext_node;
		pnext_node->_pprev = pnode;

		pnode = pnext_node;
	}
	node* plist_tail = pnext_node;
	plist_tail->_pnext = null;

	print_dll(plist_header);
	//reverse_print_dll(plist_tail);
	//reverse_dll(&plist_header);
	node* n1 = new node; n1->_data = -1;
	sorted_insert(n1, &plist_header);
	node* n2 = new node; n2->_data = 5;
	sorted_insert(n2, &plist_header);
	node* n3 = new node; n3->_data = 20;
	sorted_insert(n3, &plist_header);

	printf("insert done\n");
	print_dll(plist_header);

	return 0;
}

void reverse_dll(node** ref)
{
	if(*ref == NULL || (*ref)->_pnext == NULL)
		return;

	node* pprev = null;
	node* pcurr = *ref;
	node* pnext = null;

	while(pcurr)
	{
		pnext = pcurr->_pnext; //store addr of next node

		pcurr->_pprev = pnext; // do reverse
		pcurr->_pnext = pprev;

		pprev = pcurr; //move forward to the next node need to reverse
		pcurr = pnext;
	}

	*ref = pprev; //change header of the list to the last node
	return;
}

void print_dll(node* ref)
{
	printf("START\n");
	while(ref)
	{
		printf("%d\n", ref->_data);
		ref = ref->_pnext;
	}
	printf("END\n");
}

void reverse_print_dll(node* ref)
{
	printf("END\n");
	while(ref)
	{
		printf("%d\n", ref->_data);
		ref = ref->_pprev;
	}
	printf("START\n");
}

void insert_element(int ele, node** ref)
{
	if(!*ref)
	{
		*ref = new node;
		(*ref)->_data = ele;
		(*ref)->_pprev = (*ref)->_pnext = null;
	}

	node* pprev = null;
	node* pcurr = *ref;

	while(pcurr->_data < ele && pcurr)
	{
		pprev = pcurr;
		pcurr = pcurr->_pnext;
	}

	node* nn = new node;
	nn->_data = ele;

	if(pprev) 
		pprev->_pnext = nn; //in case insert at 1st node ,no prev

	if(pcurr) 
		pcurr->_pprev = nn; //in case insert at last node, no next

	nn->_pprev = pprev;
	nn->_pnext = pcurr;

	if(pcurr == *ref) //insert at the first node
	{
		printf("about to change header\n");
		ref = &nn;
	}

	return;
}

void sorted_insert(node* ele, node** ref)
{
	if(!*ref) //null list
		return;

	node* pcurr = *ref;
	node* pprev = null;
	while(pcurr)
	{
		if(pcurr != *ref)
			pprev = pcurr->_pprev;

		if(pcurr->_data >= ele->_data)
		{
			//insert at head
			if(pcurr == *ref)
			{
				*ref = ele;
				ele->_pprev = null;
				ele->_pnext = pcurr;
				pcurr->pprev = ele;
				return;
			}
			else
			{
				//insert at tail
				if(pcurr->_pnext == null)
				{
					ele->_pnext = null;
					pcurr->_pnext = ele;
					ele->_pprev = pcurr;
					return;
				}
				else //insert at middle	
				{
					ele->_pnext = pcurr;
					pcurr->_pprev = ele;
					pcurr->_pnext = ele;
					ele->_pprev = pcurr;
					return;
				}
			}		
		}
		pcurr = pcurr->_pnext;
	}
}
