#include "struct_defines_leet.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>
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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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

int num_of_unique_trees(int n)
{
	vector<int> f(n+1, 0);
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			f[i] += f[j-1]*f[i-j];
		}
	}

	return f[n];
}

typedef vector<TreeNode* > vec_tree_node;
vec_tree_node generate_unique_tree(int start, int end)
{
	vec_tree_node sub_tree;
	if(start > end)
	{
		sub_tree.push_back(nullptr);
		//return sub_tree;
	}
	else
	{
		for(int k = start; k <= end; ++k)
		{
			vec_tree_node left_sub_tree = generate_unique_tree(start, k-1);
			vec_tree_node right_sub_tree = generate_unique_tree(k+1, end);
			for(auto i : left_sub_tree) //every node in l/r sub tree could become child of
			{ //k node
				for(auto j : right_sub_tree)
				{
					TreeNode *node = new TreeNode(k);
					node->left = i;
					node->right = j;
					sub_tree.push_back(node);
				}
			}
		}
		//return sub_tree;
	}

	return sub_tree;
}

vec_tree_node generate_unique_tree(int n)
{
	if(n < 1) return vec_tree_node();//generate_unique_tree(1, 0);
	else return generate_unique_tree(1, n);
}

bool is_valid_bst(TreeNode* root, int low, int up)
{
	if(nullptr == root) return true;
	else
	{
		return root->val >= low && root->val <= up &&
			   is_valid_bst(root->left, low, root->val) &&
			   is_valid_bst(root->right, root->val, up);
	}
}

bool is_valid_bst(TreeNode* root, TreeNode* min_node, TreeNode* max_node)
{
	if(nullptr == root) return true;
	else if( (nullptr != min_node && root->val <= min_node->val )||
		     (nullptr != max_node && root->val >= max_node->val))
		return false;
	else
		return is_valid_bst(root->left, min_node, root) && 
			   is_valid_bst(root->right, root, max_node);

}

bool is_valid_bst(TreeNode* root)
{
	//return is_valid_bst(root, INT_MIN, INT_MAX);
	return is_valid_bst(root, nullptr, nullptr);
}

int list_length(ListNode* head)
{
	int n = 0;

	while(nullptr != head)
	{
		++n; head = head->next;
	}

	return n;
}

ListNode* nth_node(ListNode* head,  int n)
{
	while(--n && nullptr != head)
		head = head->next;

	return head;
}

TreeNode* sorted_list_to_bst(ListNode* head, int len)
{
	if(len == 0) return nullptr;
	else if(len == 1) return new TreeNode(head->val);

	TreeNode* root = new TreeNode(nth_node(head, len/2+1)->val);
	root->left = sorted_list_to_bst(head, len/2);
	root->right = sorted_list_to_bst(nth_node(head, len/2+2), (len-1)/2);

	return root;
}

TreeNode* sorted_list_to_bst(ListNode* head)
{
	return sorted_list_to_bst(head, list_length(head));
}

/*template<class T>
static inline T min(T a, T b)
{
	return a >= b ? a : b;
}*/

int min_depth(TreeNode* root, bool has_brother)
{
	if(nullptr == root) return has_brother ? INT_MAX : 0;
	else
		return 1 + min(min_depth(root->left, root->right != nullptr), 
			min_depth(root->right, root->left != nullptr));
}

int min_depth(TreeNode* root)
{
	return min_depth(root, false);
}

/*template<class T>
static inline T max(T a, T b)
{
	return a >= b ? a : b;
}*/

int max_depth(TreeNode* root)
{
	if(root == nullptr) return 0;
	else
		return 1 + max(max_depth(root->left), max_depth(root->right));
}

bool has_path_sum(TreeNode* root, int sum)
{
	if(nullptr == root) return false;
	else if( root->left == nullptr && root->right == nullptr)
		return sum == root->val;
	else
		return has_path_sum(root->left, sum-root->val) ||
			   has_path_sum(root->right, sum-root->val);
}

typedef vector<vector<int> > vec_2d;
typedef vector<int> vec_1d;
void collect_path_sum(TreeNode *root, int gap, vec_1d& cur, vec_2d& res)
{
	if(nullptr == root) return;

	cur.push_back(root->val);

	if(root->left == nullptr && root->right == nullptr)
	{
		if(gap == root->val)
			res.push_back(cur);
	}
	collect_path_sum(root->left, gap - root->val, cur, res);
	collect_path_sum(root->right, gap - root->val, cur, res);
	cur.pop_back(); //draw back, ??
}

vec_2d collect_path_sum(TreeNode *root, int sum)
{
	vec_2d res;
	vec_1d cur;
	collect_path_sum(root, sum, cur, res);
	return res;
}

int depth_first_search(TreeNode *root, int sum)
{
	if(nullptr == root) return 0;
	if(nullptr == root->left && nullptr == root->right)
		return sum*10 + root->val;

	return depth_first_search(root->left, sum*10 + root->val) +
		depth_first_search(root->right, sum*10 + root->val);
}

int sum_node(TreeNode *root)
{
	return depth_first_search(root, 0);
}
