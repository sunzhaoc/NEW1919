/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-04 14:25:16
 * @LastEditTime: 2021-03-04 15:23:39
 * @FilePath: \Leetcode\646.Maximum Length of Pair Chain.cpp
 */
/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
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
TIME:     84ms    BEAT: 81.33%    O(n) = nlogn
MEMORY: 18.4MB    BEAT: 52.05%    O(n) = n
USED TIME: 37:38
LAST EDIT TIME: 2021年3月4日15:23:27
Description: 二分 + 贪心。
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [] (const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1] || (x[1] == y[1] && x[0] < y[0]);
        });

        vector<vector<int>> tail = {pairs[0]};

        for (int i = 1; i < pairs.size(); i ++) {
            int left = 0, right = tail.size() - 1;
            while (left < right) {
                int mid = (right - left) / 2 + left;
                if (tail[mid][1] < pairs[i][0]) left = mid + 1;
                else right = mid;
            }
            if (tail[left][1] < pairs[i][0]) tail.emplace_back(pairs[i]);
        }
        return tail.size();
    }
};


/*
RESULT: Accept
TIME:    272ms    BEAT: 50.07%    O(n) = n^2
MEMORY: 18.4MB    BEAT: 53.47%    O(n) = n
USED TIME: 13:01
LAST EDIT TIME: 2021年3月4日14:40:15
Description: 
*/

// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         vector<int> dp(pairs.size(), 1);
//         sort(pairs.begin(), pairs.end(), [] (const vector<int>& x, const vector<int>& y) {
//             return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
//         });
//         for (int i = 0; i < pairs.size(); i ++) {
//             for (int j = 0; j < i; j ++) {
//                 if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[j] + 1, dp[i]);
//             }
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> pairs = {{1,2}, {2,3}, {3,4}};
    int ans = sol.findLongestChain(pairs);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

