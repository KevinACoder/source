#ifndef STRUCT_DEFINES
#define STRUCT_DEFINES	

#include <stdio.h>
#include <stdlib.h>

typedef int num;
#define null NULL

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
	void delete_node(num ele, node** ref); //cannot handle occasion that has loop
	void print_list(node* ref);
	bool check_if_loop_exist(node* ref);
	node* find_the_nth_node_from_tail(node* ref, size_t n);
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

namespace binary_tree
{
	struct node
	{
		num   _data;
		node* _pleft;
		node* _pright;

		node():_pleft(null),_pright(null){}
	};

	node* create_node(num ele);
	void insert_node(node** ref, num ele);
	void populate_tree(node** ref);
	void destory_tree();

	void print_in_level_order(node* ref);//breath-first traversal
	void print_given_level(node* ref, size_t level);
	size_t height(node* ref);
};

namespace sorted_array
{
class array
{
public:
	array():_data(null),_len(0),_max_len(2)
	{
		_data = new num[_max_len];
	}
	~array()
	{
		if(_data != null)
		{
			delete[] _data;
			_data = null;
			_len = 0;
		}
	}

	void insert(num ele);
	void print() const;
	void print_unique() const;

private:
	void re_allocate();

private:
	num*   				_data;
	size_t 				_len;
	size_t 				_max_len;
	static const size_t	_resize_ratio = 2;
};

};

#endif
