#include <stdio.h>

int value = 20;

int main(int argc, char const *argv[])
{
	//12
	//2
	//1
	//2
	//1
	// 0100 | 0010 = 0110 6
	//1
	//5
	int y = 4, z = 2;
	int x = (y==z)?1:(y<z)?2:3;//3
	y | z; //6
	y || z; //1
	
	return 0;
}