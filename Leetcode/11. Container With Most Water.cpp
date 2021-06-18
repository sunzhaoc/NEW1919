/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-02 15:40:16
 * @LastEditTime: 2021-03-02 16:05:53
 * @FilePath: \Leetcode\11.Container With Most Water.cpp
 */

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:     24ms    BEAT: 78.48%    O(n) = n
MEMORY: 17.2MB    BEAT: 86.16%    O(n) = 1
USED TIME: 07:21
LAST EDIT TIME: 2021年3月2日16:2:11
Description: 双指针。判断左右两边的大小，更新较短的边，希望保留更长的边。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int ans = INT_MIN;

        while (L < R) {
            ans = max(ans, min(height[L], height[R]) * (R - L));
            if (height[L] > height[R]) R --;
            else L ++;
        }
        return ans;
    }
};


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = n^2
MEMORY: MB    BEAT: %    O(n) = 1
USED TIME: 05:16
LAST EDIT TIME: 2021年3月2日15:52:352
Description: 必定超时。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i ++) {
            for (int j = 1; j < n; j ++) {
                ans = max(ans, min(height[i], height[j]) * (j - i));
            }
        }
        return ans;
    }
};

// @lc code=end

