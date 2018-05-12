#include <stdio.h>
#include "a.h"

extern void f_two();
extern void f_three();

int main()
{
	f_two();
	f_three();
	printf("success");
	return 0;
}
