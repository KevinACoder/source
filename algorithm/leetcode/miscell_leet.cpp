#include "struct_defines_leet.h"
#include <vector>
#include <map>
#include <string>
#include <limits.h>
#include <stack>
#include <algorithm>

using namespace std;

typedef vector<int> vec_1d;
typedef vector<vec_1d> vec_2d;
typedef vector<string> vec_str;

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

int m_sqrt(int x)
{
	int low = 1;
	int high = x;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(mid > x/mid)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return high;
}

//x(n+1) = x(n) - f(x(n))/(f(x(n)'))
int m_sqrt2(int x)
{
	constexpr double epsilon = 1e-2;
	double it = x;
	while(it*it - x > epsilon) //newton's method
	{
		it = (it + x/it)/2.0; 
	}
	return (int)it;
}


int max_profit(vec_1d& prices)
{
	int n = prices.size();
	if(n < 2) return 0;
	vec_1d min_price(n, 0);
	vec_1d max_profit(n, 0);
	min_price[0] = prices[0];
	max_profit[0] = 0;

	for(int i = 1; i < n; ++i)
	{
		min_price[i] = min(prices[i], min_price[i-1]);
		max_profit[i] = max(prices[i] - min_price[i], max_profit[i-1]);
	}
	return max_profit[n-1];
}


int len_longest_fib_subseq(vec_1d& A)
{
	const size_t n = A.size();
	map<int, int> diff;
	for(size_t i = 0; i < n; ++i)
		diff[A[i]] = i;

	vec_2d dp(n, vec_1d(n, 2));
	int max_len = 0;
	for(size_t j = 0; j < n; ++j)
	{
		for(size_t k = j + 1; k < n; ++k)
		{
			int target_i = A[k] - A[j];
			if(target_i >= A[j])
				break;
			auto it = diff.find(target_i);
			if(it == diff.end())
				continue;
			size_t i = it->second;
			dp[j][k] = dp[i][j] + 1;
			max_len = max(max_len, dp[j][k]);
		}
	}
	return max_len;
}

vec_2d m_;
int dp(const string& s1, size_t i, const string& s2, size_t j)
{
	if(i == 0 && j == 0)
		return 0;
	else if(m_[i][j] != INT_MAX)
		return m_[i][j];
	else if (i == 0)
		return m_[i][j] = dp(s1, i, s2, j-1) + s2[j-1];
	else if (j == 0)
		return m_[i][j] = dp(s1, i-1, s2, j) + s1[i-1];
	else if (s1[i-1] == s2[j-1])
		return m_[i][j] = dp(s1, i-1, s2, j-1);
	else
		return m_[i][j] = min(dp(s1, i, s2, j-1) + s2[j-1],
						      dp(s1, i-1, s2, j) + s1[i-1]);
		
}

int minimum_delete_sum(string s1, string s2)
{
	size_t l1 = s1.length();
	size_t l2 = s2.length();
	m_ = vec_2d(l1 + 1, vec_1d(l2 + 1, INT_MAX));
	return dp(s1, l1, s2, l2);
}

int minimum_delete_sum2(string s1, string s2)
{
	size_t l1 = s1.length();
	size_t l2 = s2.length();
	vec_2d dpm_(l1+1, vec_1d(l2+1, 0));
	for(size_t i = 1; i <= l1; ++i)
		dpm_[i][0] = dpm_[i-1][0] + s1[i-1];
	for(size_t j = 1; j <= l2; ++j)
		dpm_[0][j] = dpm_[0][j-1] + s2[j-1];

	for(size_t i = 1; i <= l1; ++i)
	{
		for(size_t j = 1; j <= l2; ++j)
		{
			if(s1[i-1] == s2[j-1])
				dpm_[i][j] = dpm_[i-1][j-1];
			else
				dpm_[i][j] = min(dpm_[i-1][j] + s1[i-1],
								 dpm_[i][j-1] + s2[j-1]);
		}
	}
	return dpm_[l1][l2];
}

vec_2d d_;
int min_edit_distance(const string& s1, size_t l1, const string& s2, 
	size_t l2)
{
	if(l1 == 0)
		return l2;
	if(l2 == 0)
		return l1;
	if(d_[l1][l2] >= 0)
		return d_[l1][l2];

	int min_val = 0;
	if(s1[l1-1] == s2[l2-1])
		//no need to edit because the last character is identical
		min_val = min_edit_distance(s1, l1-1, s2, l2-1); 
	else
		min_val = min(min_edit_distance(s1, l1-1, s2, l2-1), //replace
				  min(min_edit_distance(s1, l1-1, s2, l2), //insert
				  	  min_edit_distance(s1, l1, s2, l2-1))) + 1; //delete

	return d_[l1][l2] = min_val;
}

int min_edit_distance(string word1, string word2)
{
	size_t l1 = word1.length();
	size_t l2 = word2.length();
	d_ = vec_2d(l1+1, vec_1d(l2+1, -1));
	return min_edit_distance(word1, l1, word2, l2);
}

vec_1d daily_temp(vec_1d& temp)
{
	const int n = temp.size();
	stack<int> s;
	vec_1d res(n);

	for(int i = n-1; i >= 0; --i)
	{
		while(!s.empty() && s.top() <= temp[i])
			s.pop();

		res[i] = s.empty()?0:s.top() - i;
		s.push(i);
	}
	return res;
}

vec_2d transpos_matrix(vec_2d& mat)
{
	size_t row = mat.size();
	size_t col = mat[0].size();
	vec_2d trans_mat(col, vec_1d(row, 0));
	for(size_t i = 0; i < row; ++i)
	{
		for(size_t j = 0; j < col; ++j)
		{
			trans_mat[j][i] = mat[i][j];
		}
	}
	return trans_mat;
}

vec_str summary_range(vec_1d& nums)
{
	int start = 0;
	int end = 0;
	size_t n = nums.size();
	vec_str report;

	for(size_t i = 1; i < n; ++i)
	{
		if( start == n-1 || nums[i] != nums[i-1]+1)
		{
			end = i-1;
			if(start == end)
				report.push_back(to_string(nums[start]));
			else
				report.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
			start = i;
		}
	}
	return report;
}