#include "struct_defines_leet.h"
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode  *left;
	TreeNode  *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x): val(x), left(nullptr), right(nullptr),
	next(nullptr) {}
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

int get_balanced_height(TreeNode *root);
template <class T>
T MAX(T a, T b)
{
	return (a >= b)?a:b;
}
template<class T>
T ABS(T a)
{
	if(a < 0) return -a;
	else return a;
}


bool is_balanced_tree(TreeNode *root)
{
	return get_balanced_height(root) >= 0;
}

int get_balanced_height(TreeNode *root)
{
	if(nullptr == root) return 0;

	int left = get_balanced_height(root->left);
	int right = get_balanced_height(root->right);

	if(left < 0 || right < 0 || ABS(left - right) > 1) return -1;
	return MAX(left, right) + 1;
}

void flatten_tree(TreeNode *root)
{
	if(nullptr == root) return;

	flatten_tree(root->left);
	flatten_tree(root->right);

	if(root->left == nullptr) return;

	TreeNode *p = root->left;
	while(p->right != nullptr) //find the last node of left tree
		p = p->right;
	p->right = root->right;//attach right tree to the last node of left tree
	root->right = root->left;//attach whole left tree to right node 
	root->left = nullptr;//deattach left tree
	return;
}

void connect(TreeLinkNode *root)
{
	if(root == nullptr) return;

	TreeLinkNode dummy(-1);
	for(TreeLinkNode *cur = root, *prev = &dummy; cur != nullptr; 
		 cur = cur->next)
	{
		if(cur->left != nullptr)
		{
			prev->next = cur->left; //move to the next level
			prev = prev->next;
		}
		if(cur->right != nullptr)
		{
			prev->next = cur->right;
			prev = prev->next;
		}
	}
	connect(dummy.next);
}

template<typename input_it>
TreeNode* build_tree(input_it pre_first, input_it pre_last, 
	input_it in_first, input_it in_last)
{
	if(pre_last == pre_first) return nullptr;
	if(in_last == in_first) return nullptr;

	TreeNode* root = new TreeNode(*pre_first);
	input_it in_root_pos = find(in_first, in_last, *pre_first); //find pos of root 
	size_t left_size = distance(in_first, in_root_pos);

	root->left = build_tree(next(pre_first), next(pre_first,
	left_size + 1), in_first, next(in_first, left_size));
	root->right = build_tree(next(pre_first, left_size + 1), pre_last,
	next(in_root_pos), in_last);

	return root;
}
TreeNode* build_tree(vec_1d& preorder, vec_1d& inorder)
{
	return build_tree(begin(preorder), end(preorder), 
		begin(inorder), end(inorder));
}


template<typename input_it>
TreeNode* build_tree_pos(input_it in_first, input_it in_last,
	input_it post_first, input_it post_last)
{
	if(in_first == in_last) return nullptr;
	if(post_first == post_last) return nullptr;

	int val = *prev(post_last);
	TreeNode *root = new TreeNode(val);

	input_it it_root = find(in_first, in_last, val);
	size_t left_size = distance(in_first, it_root);
	input_it it_post_left_last = next(post_first, left_size);

	root->left = build_tree_pos(in_first, it_root, post_first, it_post_left_last);
	root->right = build_tree_pos(next(it_root), in_last, it_post_left_last,
		prev(post_last));

	return root;
}
TreeNode* build_tree_pos(vec_1d& inorder, vec_1d& postorder)
{
	return build_tree_pos(begin(inorder), end(inorder), 
		begin(postorder), end(inorder));
}
