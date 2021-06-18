/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-17 15:15:15
 * @LastEditTime: 2020-12-17 20:19:27
 * @FilePath: \Leetcode\714.Best Time to Buy and Sell Stock with Transaction Fee.cpp
 */
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:    196ms    BEAT: 91.69%    O(n) = n
MEMORY: 50.9MB    BEAT: 65.52%    O(n) = 1
Description: 贪心。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = prices[0] + fee;
        int profit = 0;

        for(int i = 1; i < prices.size(); i ++) {
            if (prices[i] + fee < buy) {
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        
        return profit;
    }
};


int main () {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int ans = sol.maxProfit(prices, 2);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

