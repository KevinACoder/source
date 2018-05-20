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
};