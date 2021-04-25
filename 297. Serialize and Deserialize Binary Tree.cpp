/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-02 10:47:22
 * @LastEditTime: 2021-04-04 15:34:36
 * @FilePath: \Leetcode\297.Serialize and Deserialize Binary Tree.cpp
 */
/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start

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
TIME:     52ms    BEAT: 73.69%    O(n) = 
MEMORY: 30.3MB    BEAT: 74.84%    O(n) = 
LAST EDIT TIME: 2021年4月4日15:33:19
Description: Y总的。挺简单的。
但是你不知道string输入是以"1,2,3,#,#,4,5"这种形式输入的。
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string res = "";
    string serialize(TreeNode* root) {
        res.clear();
        dfs1(root);
        return res;
    }

    void dfs1(TreeNode* node) {
        if (!node) {
            res += "#,";
            return;
        }
        
        res += to_string(node->val) + ",";
        dfs1(node->left);
        dfs1(node->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfs2(data, i);
    }

    TreeNode* dfs2(string& data, int& i) {
        if (data[i] == '#') {
            i += 2;
            return nullptr;
        }
        int t = 0;
        bool is_minus = false;
        if (data[i] == '-') {
            is_minus = true;
            i ++;
        }
        while (data[i] != ',') {
            t = t * 10 + data[i] - '0';
            i ++;
        }
        i ++;
        if (is_minus) t = - t;
        
        auto root = new TreeNode(t);
        root->left = dfs2(data, i);
        root->right = dfs2(data, i);

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

