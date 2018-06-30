#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include "struct_defines_leet.h"
using namespace std;

int strStr(string, string);

int main(int argc, char const *argv[])
{
	cout<<"leetcode string"<<endl;
	return 0;
}

int strStr(string haystack, string needle) {
    /*if(haystack.empty() || needle.empty() ||
    	needle.size() > haystack.size())
    	return 0;*/
	if(needle.empty()) return 0;

    int N = haystack.size();
    int M = needle.size();
    for(int i = 0; i < N; ++i)
    {
    	int j = i; //index of haystack
    	int k = 0; //index of needle
    	/*for(; k < M && j < N && haystack[j] == needle[k]; ++k, ++j)
    	{

    	}*/
    	while(k < M && j < N && haystack[j] == needle[k])
    	{
    		++k; ++j;
    	}
    	if(k == M)
    		return i;
    }    

    return -1;
 }

 int m_atoi(string str)
 {
 	int num = 0;
 	int sign = 1;
 	int ix = 0;
 	const int N = str.length();

 	//while(ix < N && str[ix] != '+' && str[ix] != '-'){++ix;}
 	while(ix < N && str[ix] == ' '){ix++;}

 	//if(ix >= N) return 0;

 	if(str[ix] == '+') 
 	{
 		++ix;
 	}
 	else if(str[ix] == '-')
 	{
 		sign = -1;
 		++ix;
 	}

 	num *= sign;
 	while(ix < N)
 	{
 		if(str[ix] < '0' || str[ix] > '9')
 			break;

 		if(num > INT_MAX/10 || (num == INT_MAX/10 && str[ix] - '0' > INT_MAX%10))
 			return sign == 1 ? INT_MAX : INT_MIN;

 		num = num*10 + (str[ix] - '0');
 		++ix;
 	}

 	return num*sign;
 }

string add_binary(string a, string b)
{
	int len = a.size() > b.size() ? a.size() : b.size();
	string res;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int carry = 0;
	for(int ix = 0; ix < len; ++ix)
	{
		int a1 = ix < a.size() ? a[ix] - '0' : 0;
		int a2 = ix < b.size() ? b[ix] - '0' : 0;
		int sum = (a1 + a2 + carry)%2;
		carry = (a1 + a2 + carry)/2;
		res.insert(res.begin(), sum + '0');
	}

	if(carry > 0)
		res.insert(res.begin(), '1');

	return res;
}

string longest_common_prefix(vector<string>& strs)
{

	return "";
}

