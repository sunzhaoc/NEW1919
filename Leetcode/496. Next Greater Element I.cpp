/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-05 13:17:34
 * @LastEditTime: 2021-03-17 21:36:03
 * @FilePath: \Leetcode\496.Next Greater Element I.cpp
 */
/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
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
TIME:     4ms    BEAT: 95.92%    O(n) = 
MEMORY: 8.6MB    BEAT: 61.77%    O(n) = 
LAST EDIT TIME: 2021年3月17日21:25:45
Description: 二刷。不会。
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i ++) {
            while (!st.empty() && nums2[i] > st.top()) {
                int tmp = st.top();
                st.pop();
                map[tmp] = nums2[i];
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i ++) {
            nums1[i] = map.find(nums1[i]) != map.end() ? map[nums1[i]] : -1;
        }
        return nums1;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 79.07%    O(n) = 
MEMORY: 8.6MB    BEAT: 66.98%    O(n) = 
LAST EDIT TIME: 2021年3月5日13:59:9
Description: 
*/

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         stack<int> st;
//         vector<int> ans(nums1.size(), -1);
//         unordered_map<int, int> map;
//         for (int i = 0; i < nums2.size(); i ++) {
//             while (!st.empty() && nums2[i] > nums2[st.top()]) {
//                 int id = st.top();
//                 st.pop();
//                 map[nums2[id]] = nums2[i];
//             }
//             st.push(i);
//         }
//         for (int i = 0; i < nums1.size(); i ++) {
//             if (map.find(nums1[i]) != map.end()) ans[i] = map[nums1[i]];
//         }
//         return ans;
//     }
// };


/*
RESULT: Accept
TIME:     4ms    BEAT: 97.21%    O(n) = 
MEMORY: 8.5MB    BEAT: 80.26%    O(n) = 
USED TIME: 05:12
LAST EDIT TIME: 2021年3月5日13:24:1
Description: 
*/

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans(nums1.size(), -1);
//         unordered_map<int, int> map;
//         for (int i = 0; i < nums2.size(); i ++) {
//             map[nums2[i]] = i;
//         }
//         for (int i = 0; i < nums1.size(); i ++) {
//             int id = map[nums1[i]];
//             for (int j = id + 1; j < nums2.size(); j ++) {
//                 if (nums2[j] > nums1[i]) {
//                     ans[i] = nums2[j];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    // cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

