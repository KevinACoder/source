#include "stdio.h"
#include "stdlib.h"

struct node
{
	int _data;
	struct node* _pnext;
};

void reverse_ll(node** ref);
void reverse_ll_iter(node** ref);
void print_ll(node* ref);
void reverse_print_ll(node* ref);

int main(int argc, char const *argv[])
{
	const int num = 10;
	node list[num];
	node* plist = list;

	for (int i = 0; i < num-1; ++i)
	{
		/* code */
		list[i]._data = i;
		list[i]._pnext = list + (i+1);
	}
	list[num-1]._data = num-1;
	list[num-1]._pnext = NULL;
	print_ll(list);

	//reverse_ll(&plist); 
	reverse_ll_iter(&plist);

	printf("after reverse\n");
	//print_ll(plist); //use plist instead of list, because header has been changed
	reverse_print_ll(plist);

	return 0;
}

void reverse_ll(node** ref)
{
	struct node* pfirst = NULL;
	struct node* prest = NULL;
	struct node* plast = NULL;
	if (*ref == NULL)
		return;

	pfirst = *ref; //first part of list
	prest = pfirst->_pnext; //second part of list

	if(prest == NULL)
		return;

	reverse_ll(&prest); //recursively separete list into two parts and reverse
	plast = pfirst->_pnext;
	plast->_pnext = pfirst; //do the reverse, when only three node includes

	pfirst->_pnext = NULL;
	*ref = prest;
	return;
}

void print_ll(node* ref)
{
	if(ref == NULL)
	{
		printf("End\n");
		return;
	}

	printf("%d\n", ref->_data);
	return print_ll(ref->_pnext);
}

void reverse_ll_iter(node** ref)
{
	node* pprev = NULL;
	node* pcurr = *ref;
	node* pnext = NULL;

	if(*ref == NULL || (*ref)->_pnext == NULL)
		return;

	while(pcurr != NULL)
	{
		pnext = pcurr->_pnext; //get next node in the pre-reverse list
		pcurr->_pnext = pprev; //change direction of pointer

		pprev = pcurr; //header would point to null
		pcurr = pnext; //move to next node need to reverse

	}

	*ref = pprev;
	return;
}

void reverse_print_ll(node* ref)
{
	if(ref == NULL)
	{
		//printf("%d\n", ref->_data);
		printf("End\n");
	}
	else
	{
		reverse_print_ll(ref->_pnext);
		printf("%d\n", ref->_data);
	}
	return;
}
