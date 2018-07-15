#include "struct_defines_leet.h"
#include <vector>

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