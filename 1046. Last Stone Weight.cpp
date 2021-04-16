/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-30 12:24:32
 * @LastEditTime: 2020-12-30 12:42:31
 * @FilePath: \Leetcode\1046.Last Stone Weight.cpp
 */
/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
#include <queue>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 55.68%    O(n) = nlogn
MEMORY: 6.3MB    BEAT: 39.63%    O(n) = n
Description: 最大堆
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s: stones) q.push(s);

        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a > b) q.push(a - b);
        }

        return q.empty() ? 0 : q.top();
    }
};


int main() {
    Solution sol;
    vector<int> stones = {};
    int ans = sol.lastStoneWeight(stones);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

