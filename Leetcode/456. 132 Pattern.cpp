/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-17 21:10:14
 * @LastEditTime: 2021-03-24 19:12:22
 * @FilePath: \Leetcode\456.132 Pattern.cpp
 */
/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
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
TIME:     12ms    BEAT: 89.69%    O(n) = 
MEMORY: 13.4MB    BEAT: 58.76%    O(n) = 
LAST EDIT TIME: 2021年3月24日19:9:8
Description: 二刷。还是有点难想。
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int tmp = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i --) {
            if (nums[i] < tmp) return true;
            while (!st.empty() && nums[i] > st.top()) {
                tmp = max(tmp, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};


/*
RESULT: Accept
TIME:      8ms    BEAT: 98.59%    O(n) = 
MEMORY: 13.4MB    BEAT: 56.40%    O(n) = 
LAST EDIT TIME: 2021年3月18日18:15:27
Description: 太难想了吧。这还不算hard？
*/

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
    
//         int tmp = INT_MIN;
//         stack<int> st;
//         for (int i = nums.size() - 1; i >= 0; i --) {
//             if (nums[i] < tmp) return true;
//             while (st.size() && nums[i] > st.top()){
//                 tmp = max(tmp, st.top());
//                 st.pop();
//             }
//             st.push(nums[i]);
//         }
//         return false;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {1,0,1,-4,-3};
    // vector<int> nums = {1,2,3,4};
    // vector<int> nums = {-2,1,1};
    vector<int> nums = {1,3,2,4,5,6,7,8,9,10};
    bool ans = sol.find132pattern(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

