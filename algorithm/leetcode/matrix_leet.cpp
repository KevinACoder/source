#include "struct_defines_leet.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

typedef vector<vector<int> > matrix;
bool search_matrix(matrix& mat, int target)
{
	if(mat.empty()) return false;
	size_t r = mat.size();
	size_t c = mat.front().size();

	int low = 0;
	int end = r*c;

	while(low < end)
	{
		int mid = low + (end - low)/2;
		int val = mat[mid/r][mid%r];

		if(val == target)
			return true;
		else if(val < target)
			low = mid + 1;
		else
			end = mid;
	}

	return false;
}

typedef vector< vector<int> > vec_2d;
typedef vector<int> vec_1d;
void subsets(const vec_1d& nums, vec_2d& res, vec_1d& rcd, int step)
{
	if(step == nums.size())
	{
		res.push_back(rcd);
		return;
	}

	subsets(nums, res, rcd, step+1);
	rcd.push_back(nums[step]);
	subsets(nums, res, rcd, step+1);
	rcd.pop_back();
}

vec_2d subsets(vec_1d& nums)
{
	sort(nums.begin(), nums.end());
	vec_2d res;
	vec_1d rcd;
	subsets(nums, res, rcd, 0);
	return res;
}

void dfs(const vec_1d& s, vec_1d::iterator start, vec_1d& rcd, vec_2d& res)
{
	res.push_back(rcd);

	for(vec_1d::iterator it = start; it != s.end(); ++it)
	{
		if(it > start && *it == *(it+1))
			continue;

		rcd.push_back(*it);
		dfs(s, it+1, rcd, res);
		rcd.pop_back();
	}
}

vec_2d subsets_with_dup(vec_1d& s)
{
	sort(s.begin(), s.end());
	vec_2d res;
	vec_1d rcd;
	dfs(s, s.begin(), rcd, res);
	return res;
}

vec_2d premute(vec_1d& num)
{
	vec_2d res;
	sort(num.begin(), num.end());

	do
	{
		res.push_back(num);
	}while(next_permutation(num.begin(), num.end()));
	return res;
}

class NumMatrix {
	typedef vector<int> vec_1d;
	typedef vector<vector<int>> vec_2d;
public:
    NumMatrix(vector<vector<int>> matrix) {
        _sums.clear();
        if(matrix.empty()) 
        	return;

        int row = matrix.size();
        int col = matrix[0].size();

        _sums = vec_2d(row+1, vec_1d(col+1, 0));
        for(int i = 1; i <= row; ++i)
        	for(int j = 1; j <= col; ++j)
        		_sums[i][j] = matrix[i-1][j-1]
        					+ _sums[i-1][j]
        					+ _sums[i][j-1]
        					- _sums[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return _sums[row2 + 1][col2 + 1]
        	 - _sums[row2 + 1][col1]
        	 - _sums[row1][col2 + 1]
        	 + _sums[row1][col1];
    }

 private:
 	vec_2d _sums;
};