/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-04 09:51:36
 * @LastEditTime: 2021-03-04 11:02:11
 * @FilePath: \Leetcode\354.Russian Doll Envelopes.cpp
 */
/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
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
TIME:    984ms    BEAT: 54.71%    O(n) = n^2
MEMORY: 13.4MB    BEAT: 75.77%    O(n) = n
LAST EDIT TIME: 
Description: 受下面一个升序，一个降序的影响。改了一下最初的code。
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [] (const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
        });
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (envelopes[j][1] < envelopes[i][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


/*
RESULT: Accept
TIME:     64ms    BEAT: 86.01%    O(n) = nlogn
MEMORY: 16.5MB    BEAT: 18.92%    O(n) = n
USED TIME: 36:43
LAST EDIT TIME: 2021年3月4日10:45:17
Description: 
*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [] (const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);   // 和下面不同的是，这里一个升序，一个降序。
        });
        vector<vector<int>> tail(envelopes.size(), vector<int> (2, 0));
        int ans = 0;
        for (auto it: envelopes) {
            int left = 0, right = ans;
            while (left < right) {
                int mid = (right - left) / 2 + left;
                // 下面两种都可以。
                // if (tail[mid][0] >= it[0] || tail[mid][1] >= it[1])right = mid;
                // else left = mid + 1;
                if (tail[mid][0] < it[0] && tail[mid][1] < it[1]) left = mid + 1;
                else right = mid;
            }
            tail[left] = it;
            if (right == ans) ans ++;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:   1352ms    BEAT: 25.98%    O(n) = n^2
MEMORY: 13.5MB    BEAT: 68.83%    O(n) = n
USED TIME: 11:49
LAST EDIT TIME: 2021年3月4日10:3:53
Description: 第300题的升级版。
*/

// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         if (envelopes.size() < 2) return envelopes.size();
//         sort(envelopes.begin(), envelopes.end(), [] (const vector<int>& x, const vector<int>& y) {
//             return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
//         });
//         vector<int> dp(envelopes.size(), 1);
//         for (int i = 0; i < envelopes.size(); i ++) {
//             for (int j = 0; j < i; j ++) {
//                 if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    // vector<vector<int>> envelopes = {{4,5}, {4,6}, {6,7}, {2,3}, {1,1}};
    int ans = sol.maxEnvelopes(envelopes);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

