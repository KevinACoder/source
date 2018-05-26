#include "struct_defines.h"

namespace bit_operations
{
	void set_bit(size_t n, int* val)
	{
		*val |= BIT_MASK(n);
	}

	void clear_bit(size_t n, int* val)
	{
		*val &= BIT_MASK(n);
	}

	int divide_7(int* val)
	{
		return (*val)<<3 - (*val);
	}

	size_t find_bits_of_one_in_number(int num)
	{
		int count = 0;
		while(num)
		{
			num &= (num - 1); //bit & cause one bit to be set as 0
			++count; //keep track of the number of bits
		}

		return count;
	}

	bool is_number_little_end()
	{
		union //store different type of data in the same memory location
		{
			short s;
			char c[sizeof(short)];
		} un;

		un.s = 0x0102;
		if(un.c[0] == 1 && un.c[1] == 2)
		{
			return false; //big end 
		}
		else if(un.c[0] == 2 && un.c[1] == 1)
		{
			return true; //little end
		}
		else
		{
			return false; //not certain
		}
	}
};