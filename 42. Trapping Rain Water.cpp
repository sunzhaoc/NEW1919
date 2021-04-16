/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-17 21:09:02
 * @LastEditTime: 2021-03-18 13:05:47
 * @FilePath: \Leetcode\42.Trapping Rain Water.cpp
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
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
TIME:      4ms    BEAT: 95.34%    O(n) = n
MEMORY: 13.8MB    BEAT: 73,76%    O(n) = 1
LAST EDIT TIME: 2021年3月18日13:4:5
Description: 双指针。有点难想。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int l = 0, r = height.size() - 1;
        int res = 0;
        int lmax = 0, rmax = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                height[l] >= lmax ? (lmax = height[l]) : res += lmax - height[l];
                l ++;
            }
            else {
                height[r] >= rmax ? (rmax = height[r]) : res += rmax - height[r];
                r --;
            }
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:      4ms    BEAT: 95.34%    O(n) = n
MEMORY: 13.9MB    BEAT: 65.96%    O(n) = n
LAST EDIT TIME: 2021年3月18日11:10:3
Description: DP空间优化，单指针。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int res = 0;
        int l = 0;
        vector<int> r(height.size(), 0);

        for (int i = height.size() - 2; i >= 0; i --) {
            r[i] = max(r[i + 1], height[i + 1]);
        }

        for (int i = 1; i < height.size() - 1; i ++) {
            l = max(l, height[i - 1]);
            int minH = min(l, r[i]);
            if (minH > height[i]) res += (minH - height[i]);
        }
        return res;
    }
};


/*
RESULT: Accept 
TIME:      4ms    BEAT: 95.34%    O(n) = n
MEMORY: 14.1MB    BEAT: 39.10 %    O(n) = n
LAST EDIT TIME: 2021年3月18日10:32:38
Description: DP
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int res = 0;
        vector<int> l(height.size(), 0);
        vector<int> r(height.size(), 0);

        for (int i = 1; i < height.size() - 1; i ++) {
            l[i] = max(l[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i --) {
            r[i] = max(r[i + 1], height[i + 1]);
        }

        for (int i = 1; i < height.size(); i ++) {
            int minH = min(l[i], r[i]);
            if (minH > height[i]) res += (minH - height[i]);
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 47.88%    O(n) = n
MEMORY: 14.1MB    BEAT: 37.38%    O(n) = n
USED TIME: 06:14
LAST EDIT TIME: 2021年3月18日10:17:56
Description: 栈。优化。
*/

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int res = 0;
//         stack<int> st;
//         int cur = 0;

//         while (cur < height.size()) {
//             while (!st.empty() && height[cur] > height[st.top()]) {
//                 int h = height[st.top()];
//                 st.pop();
//                 if (st.empty()) break;
//                 int dis = cur - st.top() - 1;
//                 res += dis * (min(height[st.top()], height[cur]) - h);
//             }
//             st.push(cur);
//             cur ++;
//         }
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     12ms    BEAT: 47.88%    O(n) = n
MEMORY: 14.8MB    BEAT:  5.16%    O(n) = n
USED TIME: 46:29
LAST EDIT TIME: 2021年3月18日9:59:38
Description: 栈。
自己能写出来就不错了，要什么自行车。
*/

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if (height.size() <= 2) return 0;
//         stack<int> st;
//         int res = 0;

//         int id;
//         for (int i = 0; i < height.size(); i ++) {
//             if (height[i] != 0) {
//                 id = i;
//                 break;
//             } 
//         }

//         int stMax = height[id];
//         for (int i = id; i < height.size(); i ++) {
//             if (st.empty() || height[i] <= st.top()) st.push(height[i]);
//             else if (height[i] > st.top()) {
//                 int num = 0;
//                 int sum = 0;
//                 int tmp = height[i];
//                 while (!st.empty() && st.top() <= height[i]) {
//                     sum += st.top();
//                     int tmp2 = st.top();
//                     st.pop();
//                     if (st.empty()) tmp = min(tmp, tmp2);
//                     num ++;
//                 }
//                 res += (tmp * num - sum);
//                 while (num) {
//                     st.push(height[i]);
//                     num --;
//                 }
//                 st.push(height[i]);
//             }

//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    // vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> nums = {};
    int ans = sol.trap(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

