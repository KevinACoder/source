#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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
	if(strs.empty()) return "";

	for(int ix = 0; ix < strs[0].size(); ++ix)
	{
		for(vector<string>::iterator it = strs.begin(); 
			it != strs.end(); ++it)
		{
			if((*it)[ix] != strs[0][ix])
				return strs[0].substr(0, ix);
		}
	}

	return strs[0];
}

bool isNumber(char const* s)
{
	char* pend = NULL;
	strtod(s, &pend);

	if(pend == s)
		return false;

	while(*pend)
	{
		if(!isspace(*pend))
			return false;
		++pend;
	}

	return true;
}

string int_to_roman(int num)
{
	static const int radix[] = {1000, 900, 500, 400, 100, 90,
	50, 40, 10, 9, 5, 4, 1};
	static const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
	"L", "XL", "X", "IX", "V", "IV", "I"};

	string roman;
	int i = 0;
	while(num > 0)
	{
		int count = num/radix[i];
		num %= radix[i];
		while(count > 0)
		{
			roman += symbol[i];
			--count;
		}
		++i;
	}

	return roman;
}

int roman_to_int(string s)
{
	static bool binit = false;
	static map<char, int> map_roman;
	if(!binit)
	{
		map_roman['I'] = 1;
		map_roman['V'] = 5;
		map_roman['X'] = 10;
		map_roman['L'] = 50;
		map_roman['C'] = 100;
		map_roman['D'] = 500;
		map_roman['M'] = 1000;
		binit = true;
	}

	int res = 0;
	for(size_t i = 0; i < s.size(); ++i)
	{
		if(i > 0 && map_roman[s[i]] > map_roman[s[i-1]])
			res += map_roman[s[i]] - 2*map_roman[s[i-1]];
		else
			res += map_roman[s[i]];
	}

	return res;
}


