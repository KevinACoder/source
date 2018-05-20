#ifndef STRUCT_DEFINES
#define STRUCT_DEFINES	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

class array_2d
{
public:
	array_2d():_data(null),_height(2),_width(2)
	{
		_data = new num*[_height];
		for(size_t i = 0; i < _height; ++i)
			_data[i] = new num[_width];
	}
	~array_2d()
	{
		for (size_t i = 0; i < _height; ++i)
		{
			/* code */
			delete[] _data[i];
			_data[i] = null;
		}

		delete[] _data;
		_data = null;
	}

	void populate_array();
	void print();

private:
	num**				_data;
	size_t				_height;
	size_t				_width;
	
};

class string
{
public:
	string():_data(null),_len(0),_max_len(10),_resize_ratio(2)
	{
		_data = new char[_max_len];
		zero_memory(_data, _max_len);
	}
	~string()
	{
		if(_data)
		{
			delete[] _data;
			_data = null;
		}
	}
	string(const char* str):_data(null),_len(0),_max_len(10),_resize_ratio(2)
	{
		if(_data != str)
		{
		//printf("bef allocated\n");
		_data = new char[_max_len];
		zero_memory(_data, _max_len);
		//printf("aft allocated\n");

		// size_t len = 0;
		// char* pstr = const_cast<char*>(str); //cast away consts
		// while(pstr != '\0')
		// {
		// 	pstr = pstr + sizeof(char);
		// 	++len;
		// 	printf("len %d\n", len);
		// }
		size_t len = strlen(str);
		
		if(len + 1 > _max_len)
			re_allocate();
		
		for(size_t i = 0; i < len; ++i)
			_data[i] = str[i];

		_len = len;
		}
	}
	void print();
	long atoi();
	void itoa(long num, size_t bit);


private:
	void zero_memory(char* pdata, size_t len)
	{
		for(size_t i = 0; i < len; ++i)
			pdata[i] = '\0';
	}

	void re_allocate()
	{
		_max_len = _max_len*_resize_ratio;
		char* ndata = new char[_max_len];
		zero_memory(ndata, _max_len);
		for(size_t i = 0 ; i < _len; ++i)
		{
			ndata[i] = _data[i];
		}

		delete[] _data;
		_data = ndata;
	}

private:
	char*    _data;
	size_t   _len;
	size_t	 _max_len;
	size_t	 _resize_ratio;
};

};

#endif
