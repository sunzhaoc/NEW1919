/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 14:38:14
 * @LastEditTime: 2021-01-05 14:58:57
 * @FilePath: \Leetcode\剑指 Offer 33. 二叉搜索树的后序遍历序列.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.1MB    BEAT:  80.61%    O(n) = 
USED TIME:
Description: 递归。
*/

class Solution {
public:
    bool valid(vector<int>& node, int left, int right) {
        if (left >= right) return true;
        int val = node[right];

        int temp = left;
        while (temp < right && node[temp] < val) 
        {
            temp ++;
        }

        for (int i = temp; i < right; i ++) {
            if(node[i] < val) return false;
        }

        return valid(node, left, temp - 1) && valid(node, temp, right - 1);
        
    }

    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() < 2) return true;
        return valid(postorder, 0, postorder.size() - 1);
    }
};
