#include "struct_defines_leet.h"
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode  *left;
	TreeNode  *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

vector<int> pre_order_traversal(TreeNode* root)
{
	vector<int> res;
	stack<const TreeNode* > s;
	if(root != nullptr)
		s.push(root);

	while(!s.empty())
	{
		const TreeNode *p = s.top();
		res.push_back(p->val);
		s.pop(); 

		if(p->right != nullptr) s.push(p->right);
		if(p->left != nullptr) s.push(p->left);
	}
	return res;
}

vector<int> pre_order_morris_traversal(TreeNode* root)
{
	vector<int> res;
	TreeNode *cur = root, *prev = nullptr;

	while(nullptr != cur)
	{
		if(cur->left == nullptr)
		{
			res.push_back(cur->val);
			prev = cur; //already access to cur node
			cur = cur->right;
		}
		else
		{
			TreeNode *node = cur->left;
			while(node->right != nullptr && 
				node->right != cur)
				node = node->right; //move to right

			if(nullptr == node->right)
			{
				res.push_back(cur->val);
				node->right = cur; //add index
				prev = cur;
				cur = cur->left;
			}
			else
			{
				node->right = nullptr;
				cur = cur->right;
			}
		}
	}
	return res;
}

typedef vector<int> vec_1d;
typedef vector<vector<int> > vec_2d;

void level_order2(TreeNode *root, int level, vec_2d& res)
{
	if(nullptr == root) return;

	if(level > res.size())
		res.push_back(vec_1d());

	res[level - 1].push_back(root->val);
	level_order2(root->left, level+1, res);
	level_order2(root->right, level+1, res);
}

vec_2d level_order(TreeNode *root)
{
	vec_2d res;
	level_order2(root, 1, res);
	return res;
}

void zigzag_level_order2(TreeNode *root, int level, vec_2d& res,
	bool bleft_to_right)
{
	if(nullptr == root) return;

	if(level > res.size())
		res.push_back(vec_1d());

	if(bleft_to_right)
		res[level-1].push_back(root->val);
	else
		res[level-1].insert(res[level-1].begin(), root->val);

	zigzag_level_order2(root->left, level+1, res, !bleft_to_right);
	zigzag_level_order2(root->right, level+1, res, !bleft_to_right);
}

vec_2d zigzag_level_order(TreeNode *root)
{
	vec_2d res;
	zigzag_level_order2(root, 1, res, true);
	return res;
}

bool is_same_tree(TreeNode *p, TreeNode *q)
{
	if(p == nullptr && q == nullptr) 
		return true;
	if(p == nullptr || q == nullptr)
		return false;
	return p->val == q->val
	  && is_same_tree(p->right, q->right)
	  && is_same_tree(p->left, q->left);
}

bool isSymmetric(TreeNode *p, TreeNode *q) 
{
	if (p == nullptr && q == nullptr) 
		return true; //
	if (p == nullptr || q == nullptr) 
		return false; // 
	return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}
bool isSymmetric(TreeNode *root) 
{
	if (root == nullptr) 
		return true;
	return isSymmetric(root->left, root->right);
}