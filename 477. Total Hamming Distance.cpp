/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-09 20:53:47
 * @LastEditTime: 2021-03-09 21:14:35
 * @FilePath: \Leetcode\477.Total Hamming Distance.cpp
 */
/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
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
#include <stack>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:     40ms    BEAT: 94.46%    O(n) = 
MEMORY: 17.6MB    BEAT: 53.10%    O(n) = 
USED TIME: 04:49
LAST EDIT TIME: 2021年3月9日21:11:39
Description: 用了数学知识。
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> st(32, 0);
        for (int num: nums) {
            int i = 0;
            while (num) {
                st[i] += num & 1;
                num >>= 1;
                i ++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            res += st[i] * (n - st[i]);
        }
        return res;
    }
};


/*
RESULT: Time Out
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                ans += calHamming(nums[i], nums[j]);
            }
        }
        return ans;
    }
    
    int calHamming(int x, int y) {
        int tmp = x ^ y;
        int ans = 0;
        while (tmp) {
            if (tmp & 1) ans ++;
            tmp >>= 1;
        }
        return ans;
    }
};

// @lc code=end

