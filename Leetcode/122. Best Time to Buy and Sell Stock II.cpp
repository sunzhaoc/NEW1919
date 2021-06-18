/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-25 16:57:20
 * @LastEditTime: 2021-03-25 17:18:26
 * @FilePath: \Leetcode\122.Best Time to Buy and Sell Stock II.cpp
 */
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
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
TIME:      4ms    BEAT: 92.08%    O(n) = n
MEMORY: 12.7MB    BEAT: 36.04%    O(n) = 1
LAST EDIT TIME: 2021年3月25日17:17:53
Description: 贪心。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i ++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 54.55%    O(n) = 
MEMORY: 12.6MB    BEAT: 57.29%    O(n) = 
USED TIME: 14:05
LAST EDIT TIME: 2021年3月25日17:13:17
Description: 二刷。之前是python。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0;
        int res = 0;
        while (r < prices.size()) {
            if (r + 1 < prices.size() && prices[r + 1] <= prices[r]) {
                if (l != r) res += prices[r] - prices[l];
                l = r + 1;
            }
            r ++;
            
        }
        if (l != r - 1) res += prices[r - 1] - prices[l];
        
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int ans = sol.maxProfit(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

