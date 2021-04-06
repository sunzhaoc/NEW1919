/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-16 19:56:27
 * @LastEditTime: 2021-03-16 20:06:17
 * @FilePath: \Leetcode\demo.cpp
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
TIME:   12ms    BEAT: 90.60%    O(n) = 
MEMORY: 21MB    BEAT: 66.06%    O(n) = 
LAST EDIT TIME: 2021年3月16日20:6:21
Description: 又没写出来，哭了。
*/

class Solution {
public:
    typedef long long LL;
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, LL lower, LL upper) {
        if (node == nullptr) return true;
        if (node->val <= lower || node->val >= upper) return false;

        return dfs(node->left, lower, node->val) && dfs(node->right, node->val, upper);
    }
};