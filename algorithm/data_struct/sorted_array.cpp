#include "struct_defines.h"

namespace sorted_array
{
	void array::insert(num ele)
	{
		if(_len + 1 > _max_len) //reallocate memory
			re_allocate();

		if(_len == 0)
		{
			_data[0] = ele;
			++_len;
		}
		// else if( _len > 0 && ele < _data[0]) //insert before header
		// {
		// 	for(int j = _len - 1; j >= 0; --j)
		// 	{
		// 		_data[j+1] = _data[j];
		// 	}
		// 	_data[0] = ele;
		// 	++_len;
		// }
		else
		{
			int i = 0;
			for(i; i < _len; ++i) //find the first element that greater than ele, i
			{
				if(_data[i] > ele)
					break;
			}
			//printf("try to insert %d at pos %d, len %d\n", ele, i, _len);

			//use int instead of unsigned in here because j could be -1
			// unsigned int -1 >= 0 would be true
			int j = _len - 1; 
			for(j; j >= i; --j) //move ele aft pos i one element backward
			{
				//printf("%d to %d \n", j, j+1);
				_data[j+1] = _data[j]; 
			}

			//printf("moved\n");

			_data[i] = ele; //insert data
			++_len;
		}

	}

	void array::print() const
	{
		for(size_t i = 0; i < _len; ++i)
			printf("%d\n", _data[i]);
	}

	void array::print_unique() const
	{
		for (size_t i = 0; i < _len; ++i)
		{
			if(i > 0 && _data[i-1] == _data[i])
				continue;

			printf("%d\n", _data[i]);
		}
	}

	void array::re_allocate()
	{
		printf("reallocate\n");
		_max_len = _max_len*_resize_ratio;
		num* pndata = new num[_max_len];

		for(size_t i = 0; i < _len; ++i)
		{
			pndata[i] = _data[i];
		}

		delete[] _data;
		_data = pndata;
	}
};