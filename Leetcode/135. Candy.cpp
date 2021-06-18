/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-24 10:25:27
 * @LastEditTime: 2020-12-24 10:45:07
 * @FilePath: \Leetcode\135.Candy.cpp
 */
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;


/*
RESULT: Accept
TIME:     40ms    BEAT: 82.13%    O(n) = n
MEMORY: 17.4MB    BEAT: 12.61%    O(n) = n
Description: 贪心。
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1)    return 1;
        vector<int> candy1(ratings.size(), 1), candy2(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i ++) {
            if (ratings[i] > ratings[i - 1])    candy1[i] = candy1[i - 1] + 1;
            if (ratings[ratings.size() - 1 - i] > ratings[ratings.size() - i])  candy2[ratings.size() - i - 1] = candy2[ratings.size() - i] + 1;
        }

        int sum = 0;
        for (int i = 0; i < ratings.size(); i ++) {
            sum += max(candy1[i], candy2[i]);
        }

        return sum;
    }
};


int main() {
    Solution sol;
    // vector<int> ratings = {1, 2, 2};
    vector<int> ratings = {1, 0, 2};
    int ans = sol.candy(ratings);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

