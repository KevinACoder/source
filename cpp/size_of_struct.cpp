#include <stdio.h>
//#include <iostream>
//using std::cout;
//using std::endl;

class ca
{
	int _a; //4  the size of structure must be times of its member
	short _b; //2->4   4-4(1)-4-4(1) = 16
	int _c; //4
	char _d;//1->4
};

class cb
{
	double _a; //8  8-2+4-8 =  24
	short _b; //2 - 4
	int _c;
	char _d; //1
};

int main()
{
	//cout<<"ca size "<<sizeof(ca)<<endl;
        printf("sizoef of ca is %d", sizeof(ca));
	printf("sizoef of cb is %d", sizeof(cb));
	//cout<<"cb size "<<sizeof(cb)<<endl;

	return 0;
}
