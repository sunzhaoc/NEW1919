/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-06 18:43:23
 * @LastEditTime: 2021-04-06 19:29:02
 * @FilePath: \Leetcode\109.Convert Sorted List to Binary Search Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;


/*
RESULT: Accept
TIME:     36ms    BEAT: 74.29%    O(n) = 
MEMORY: 30.5MB    BEAT: 33.15%    O(n) = 
USED TIME: 36:43
LAST EDIT TIME: 2021年4月6日19:21:50
Description: 以前有看过。
分治 + 中序遍历的性质。
中间为当前节点。
左边的为左子树，右边的为右子树。
我不相信这题的76.3%的通过率。
*/

class Solution {
public:
    vector<int> nums;
    TreeNode* sortedListToBST(ListNode* head) {
        for (auto it = head; it; it = it->next) nums.push_back(it->val);
        int l = 0, r = nums.size() - 1;
        auto root = buildTree(l, (r - l + 1) / 2, r);
        return root;
    }

    TreeNode* buildTree(int l, int mid, int r) {
        if (l > r) return nullptr;
        TreeNode* node = new TreeNode(nums[mid]);
        node->right = buildTree(mid + 1, midCal(mid + 1, r), r);
        node->left = buildTree(l, midCal(l, mid - 1), mid - 1);
        return node;
    }

    int midCal(int l, int r) {
        return ((r - l + 1) / 2 + l);
    }
};

// @lc code=end

