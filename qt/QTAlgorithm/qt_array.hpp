#ifndef QT_ARRAY_HPP
#define QT_ARRAY_HPP

#include <vector>
#include <map>
#include <iostream>
#include "qt_binary_tree.hpp"
using std::vector;
using std::endl;
using std::cout;
using std::map;

typedef vector<int> vec_int;
typedef vector<int>::iterator it_vec_int;
typedef map<int, int> occ_count;

namespace array
{
    vec_int intersection(vec_int& num1, vec_int& num2)
    {
        vec_int sect;
        occ_count num_count;

        for(it_vec_int it = num1.begin(); it != num1.end(); ++it)
        {
            num_count[*it]++;
        }

        for(it_vec_int it = num2.begin(); it != num2.end(); ++it)
        {
            if(num_count[*it] > 0)
            {
                sect.push_back(*it);
                num_count[*it]--;
            }
        }

        return sect;
    }

    //in sorted array
    int remove_duplicates(vec_int& nums)
    {
        if(nums.size() < 2)
            return nums.size();

        it_vec_int it_first = nums.begin();
        it_vec_int it_second = nums.begin() + 1;

        while(it_second != nums.end())
        {
            if(*it_first == *it_second)
            {
                nums.erase(it_first);
            }
            else
            {
                it_first = it_second;
                ++it_second;
            }
        }

        return nums.size();
    }

    void print_array(vec_int& nums)
    {
        for(it_vec_int it = nums.begin(); it != nums.end(); ++it)
            cout<<"["<<*it<<"]"<<endl;
    }

    //in sorted array
    void merge_array(vec_int& num1, vec_int& num2)
    {
        vec_int num_sum;
        it_vec_int it1 = num1.begin();
        it_vec_int it2 = num2.begin();

        while(it1 != num1.end() && it2 != num2.end())
        {
            if(*it1 <= *it2)
            {
                num_sum.push_back(*it1);
                ++it1;
            }
            else
            {
                num_sum.push_back(*it2);
                ++it2;
            }
        }

        if(it1 != num1.end())
        {
            num_sum.insert(num_sum.end(), it1, num1.end());
        }
        else if(it2 != num2.end())
        {
            num_sum.insert(num_sum.end(), it2, num2.end());
        }

        num1 = num_sum;
    }

    void merge_array(vec_int& num1, int m, vec_int& num2, int n)
    {
        num1.insert(num1.begin() + m + 1, num2.begin(), num2.begin() + n);
        std::sort(num1.begin(), num1.end());
    }

    TreeNode* convert_sorted_array_to_bst(vec_int& nums, int start, int end)
    {
        if(start > end)
            return nullptr;

        int mid = (start + end)/2;
        TreeNode* nn = new TreeNode(nums[mid]);

        nn->left = convert_sorted_array_to_bst(nums, start, mid-1);
        nn->right = convert_sorted_array_to_bst(nums, mid+1, end);

        return nn;
    }

    TreeNode* convert_sorted_array_to_bst_helper(vec_int& nums)
    {
        return convert_sorted_array_to_bst(nums, 0, nums.size()-1);
    }

    //applied in sorted array
    vec_int find_two_sum(vec_int nums, int target)
    {
        int len = nums.size();
        if(len < 2)
            return {0,0};

        int num_one = nums[0];
        int num_two = nums[1];
        for(int i = 1; i < len; ++i)
        {
            num_two = nums[i];

            if(nums[i] == nums[i+1] && nums[i] + nums[i+1] != target)
                continue;

            if(num_one + num_two == target)
            {
                return {0,i};
            }
        }

        for(int i = 1; i < len; ++i)
        {
            num_one = nums[i];

            it_vec_int it = std::find(nums.begin() + 1, nums.end(), target-num_one);
            if(it != nums.end())
                return {i, static_cast<int>(it-nums.begin())};
        }

        return {0, 0};
    }
};

namespace test_array {
 using namespace array;
 void test_remove_duplicates()
 {
     int arr[5] = {1,2,3,3,4};
     vec_int nums(arr, arr + 5);
     remove_duplicates(nums);
     print_array(nums);
 }

 void test_merge_array()
 {
     int arr1[9] = {1,2,4,6,9,0,0,0,0};
     int arr2[4] = {2,5,5,6};
     vec_int num1(arr1, arr1 + 5);
     vec_int num2(arr2, arr2 + 4);
     merge_array(num1, 5, num2, 4);
     print_array(num1);
 }
}


#endif // QT_ARRAY_HPP
