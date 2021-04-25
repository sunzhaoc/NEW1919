/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-05 14:05:04
 * @LastEditTime: 2021-03-05 14:33:08
 * @FilePath: \Leetcode\503.Next Greater Element II.cpp
 */
/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
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
TIME:     32ms    BEAT: 96.12%    O(n) = 
MEMORY: 22.5MB    BEAT: 70.49%    O(n) = 
LAST EDIT TIME: 2021年3月5日14:31:37
Description: 如果增长数组，可以用取模操作。
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(nums.size(), -1);

        for (int i = 0; i < nums.size() * 2; i ++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                int id = st.top();
                st.pop();
                ans[id] = nums[i % n];
            }
            st.push(i % n);
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     44ms    BEAT: 73.16%    O(n) = 
MEMORY: 24.4MB    BEAT:  8.31%    O(n) = 
USED TIME: 10:56
LAST EDIT TIME: 2021年3月5日14:17:34
Description: 环形问题只要数组长度加倍就可以了。
*/

// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; i ++) {
//             nums.emplace_back(nums[i]);
//         }
//         stack<int> st;
//         vector<int> ans(nums.size(), -1);
//         for (int i = 0; i < nums.size(); i ++) {
//             while (!st.empty() && nums[i] > nums[st.top()]) {
//                 int id = st.top();
//                 st.pop();
//                 ans[id] = nums[i];
//             }
//             st.push(i);
//         }
//         return {ans.begin(), ans.begin() + n};
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {1,2,1};
    auto ans = sol.nextGreaterElements(nums);
    system("pause");
    return 0;
}

// @lc code=end

