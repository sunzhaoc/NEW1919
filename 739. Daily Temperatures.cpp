/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-05 10:21:22
 * @LastEditTime: 2021-03-05 13:14:43
 * @FilePath: \Leetcode\739.Daily Temperatures.cpp
 */
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
using namespace std;


/*
RESULT: Accept
TIME:     64ms    BEAT: 89.85%    O(n) = 
MEMORY: 38.7MB    BEAT: 71.62%    O(n) = 
LAST EDIT TIME: 2021年3月5日13:13:48
Description: 下面的优化版本，复杂度一样的。
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<int> st;
        for (int i = 0; i < T.size(); i ++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int temp = st.top();
                st.pop();
                ans[temp] = i - temp;
            }
            st.push(i);
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:    156ms    BEAT: 12.72%    O(n) = 
MEMORY: 58.4MB    BEAT:  5.01%    O(n) = 
USED TIME: 18:09
LAST EDIT TIME: 2021年3月5日11:11:3
Description: 
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<vector<int>> stack1; // id, val
        vector<int> ans(T.size(), 0);
        for (int i = 0; i < T.size(); i ++) {
            if (stack1.empty() || T[i] <= stack1.top()[1]) {
                stack1.push({i, T[i]});
            }
            else {
                while (!stack1.empty() && T[i] > stack1.top()[1]) {
                    ans[stack1.top()[0]] = i - stack1.top()[0];
                    stack1.pop();
                }
                stack1.push({i, T[i]});
            }
        }
        return ans;
    }
};


/*
RESULT: Time Out
TIME: O(n) = n^2
LAST EDIT TIME: 2021年3月5日10:47:21
Description: 
*/

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         vector<int> ans(T.size(), 0);
//         for (int i = 0; i < T.size() - 1; i ++) {
//             if (T[i] < 100){
//                 for (int j = i + 1; j < T.size(); j ++) {
//                     if (T[j] > T[i]) {
//                         ans[i] = j - i;
//                         break;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = sol.dailyTemperatures(T);
    // cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

