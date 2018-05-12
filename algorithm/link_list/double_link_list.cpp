#include <stdio.h>
#include <stdlib.h>

#define null NULL

struct node
{
	int _data;
	struct node* _pnext;
	struct node* _pprev;
};

void reverse_dll(node** ref);
void print_dll(node* ref);
void reverse_print_dll(node* ref);

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
	reverse_dll(&plist_header);
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
