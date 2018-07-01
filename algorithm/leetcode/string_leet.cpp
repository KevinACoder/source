#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
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

vector<vector<string> > group_anagrams(vector<string>& strs)
{
	typedef vector<string> vec_1d;
	typedef vector<vector<string> > vec_2d;
	typedef map<string, vector<string> > map_str;
	map_str group;
	vec_1d group_keys;
	for(vec_1d::iterator it = strs.begin(); it != strs.end(); ++it)
	{
		string skey = *it;
		sort(skey.begin(), skey.end());
		group[skey].push_back(*it);
		if(group_keys.end() == find(group_keys.begin(), group_keys.end(), skey))
			group_keys.push_back(skey);
	}

	vec_2d res;
	for(vec_1d::iterator it_key = group_keys.begin(); it_key != group_keys.end(); ++it_key)
	{
		vec_1d rec;
		for(vec_1d::iterator it_group_item = group[*it_key].begin(); 
			it_group_item != group[*it_key].end(); ++it_group_item)
		{
			rec.push_back(*it_group_item);
		}

		res.push_back(rec);
	}

	return res;
}

string simplify_path(string& path)
{
	typedef vector<string> vec_1d;
	vec_1d dirs;

	for(auto it_1 = path.begin(); it_1 != path.end(); ) 
	{
		++it_1;
		auto it_2 = find(it_1, path.end(), '/');
		auto dir = string(it_1, it_2);

		if(!dir.empty() && dir != ".")
		{
			if(dir == "..")
			{
				if(!dirs.empty()) 
					dirs.pop_back();
			}
			else
				dirs.push_back(dir);
			
		}

		it_1 = it_2;
	}

	stringstream res;
	if(dirs.empty())
		res<<"/";
	else
	{
		for(vec_1d::iterator it = dirs.begin(); it != dirs.end(); ++it)
		    res<<"/"<<*it;
	}

	return res.str();
}

int length_of_lasy_word(string s)
{
	string::reverse_iterator it_start_of_last_word = find_if(s.rbegin(), 
		s.rend(), ::isalpha);
	string::reverse_iterator it_end_of_last_word = find_if_not(it_start_of_last_word, s.rend(), 
		::isalpha);
	return distance(it_start_of_last_word, it_end_of_last_word);
}

bool is_valid_parenthese(string s)
{
	static const string left_symbol = "[({";
	static const string right_symbol = "])}";
	stack<char> chstack;

	for(string::iterator it = s.begin(); it != s.end(); ++it)
	{
		if(find(left_symbol.begin(), left_symbol.end(), *it) != left_symbol.end())
		//if(left_symbol.find(it) != string::npos)
		{
			chstack.push(*it);
		}
		else //if(find(right_symbol.begin(), right_symbol.end(), *it) != right_symbol.end())
		{
			if(chstack.empty() || chstack.top() != left_symbol[right_symbol.find(*it)])
			//if((chstack.empty()) || chstack.top() != )
				return false;
			else
				chstack.pop();
		}
	}

	return chstack.empty();
}
