/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 16:39:58
 * @LastEditTime: 2021-03-16 16:50:28
 * @FilePath: \Leetcode\demp.cpp
 */



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     28ms    BEAT: 52.68%    O(n) = 
MEMORY: 23.8MB    BEAT: 75.41%    O(n) = 
USED TIME: 08:51
LAST EDIT TIME: 2021年3月16日16:49:54
Description: 每次取中间的。
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }   

    TreeNode* dfs(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int mid = (r - l) / 2 + l;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }
};
