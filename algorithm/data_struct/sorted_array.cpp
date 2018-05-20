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
		//printf("reallocate\n");
		_max_len = _max_len*_resize_ratio;
		num* pndata = new num[_max_len];

		for(size_t i = 0; i < _len; ++i)
		{
			pndata[i] = _data[i];
		}

		delete[] _data;
		_data = pndata;
	}

	void array_2d::populate_array()
	{
		for(size_t i = 0; i < _height; ++i)
		{
			for(size_t j = 0; j < _width; ++j)
			{
				_data[i][j] = i+j;
			}
		}
	}

	void array_2d::print()
	{
		for(size_t i = 0; i < _height; ++i)
		{
			for(size_t j = 0; j < _width; ++j)
			{
				printf("[%d, %d] %d\n", i, j, _data[i][j]);
			}	
		}	
	}

	void string::print()
	{
		printf("%s\n", _data);
	}

	long string::atoi()
	{
		if(_len <1)
			return 0;

		int sign = 0; //sign of number
		if(_data[0] == '-')
			sign = -1;
		else if(_data[0] == '+')
			sign = 1;

		long num = 0;
		int bit = 0; //add sum of each bits' value
		for(int i = _len-1; i > 0; --i)
		{
			if(_data[i] < '0' || _data[i] > '9') //check if it is integrate
				return 0;

			num += pow(10, bit)*(_data[i]-'0'); //0x30, 48
			//printf("%c -> %ld x %d\n", _data[i], pow(10, bit), (int)(_data[i]-48));
			++bit;
		}

		return sign*num;
	}

	void string::itoa(long num)
	{
		zero_memory(_data, _len);
		//get all bits
		long remain = num;
		long bit = 0;

		size_t ix = 0;
		do
		{
			bit = remain%10;
			remain = remain/10;
			_data[ix] = '0' + bit;
			++ix;

			if(ix + 1 > _max_len)
				re_allocate();

		}while(remain > 0); //last ix pos would be empty to hold sign

		_len = ix;

		//reverse bits
		for(size_t front = 0, back = ix; front < back; ++front, --back)
		{
			char tmp = _data[front];
			_data[front] = _data[back];
			_data[back] = tmp;
		}

		//add sign
		if(num >= 0)
		{
			_data[0] = '+';
		}
		else
		{
			_data[0] = '-';
		}
	}

	void string::to_upper()
	{
		for(size_t i = 0; i < _len; ++i)
		{
			if(_data[i] > 'a' && _data[i] < 'z')
			{
				_data[i] = _data[i] - 'a' + 'A'; 
			}
		}
	}

	void string::reverse()
	{
		//reverse bits
		for(size_t front = 0, back = _len; front < back; ++front, --back)
		{
			char tmp = _data[front];
			_data[front] = _data[back];
			_data[back] = tmp;
		}
	}

	void string::reverse_words()
	{
		//find seprated word
		int back_word_ix = _len-1;
		for(int word_ix = _len-1; word_ix >= 0; --word_ix) //back-ward look through
		{
			if(_data[word_ix] == ' ' || word_ix == 0) //if look throughed a whole word
			{
				printf("enter at %d\n", word_ix);
				if(word_ix == 0)
				{
					for(size_t front = word_ix, back = back_word_ix; 
						front < back; ++front, --back)
					{
						char tmp = _data[front];
						_data[front] = _data[back];
						_data[back] = tmp;
					}
				}
				else
				{
					for(size_t front = word_ix+1, back = back_word_ix; 
						front < back; ++front, --back)
					{
						char tmp = _data[front];
						_data[front] = _data[back];
						_data[back] = tmp;
					}
				}

				back_word_ix = word_ix;
			}
		}
	}
};