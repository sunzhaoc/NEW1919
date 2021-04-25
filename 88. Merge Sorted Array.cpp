/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-08 14:41:50
 * @LastEditTime: 2021-04-05 20:01:05
 * @FilePath: \Leetcode\88.Merge Sorted Array.cpp
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
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
TIME:     0ms    BEAT: 100.00%    O(n) = m + n
MEMORY: 8.9MB    BEAT:  33.07%    O(n) = 1
LAST EDIT TIME: 2021年4月5日20:0:49
Description: 二刷。
比以前的代码优雅多了。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int cur = m + n - 1;
        while (cur >= 0) {
            if (p1 == -1) nums1[cur --] = nums2[p2 --];
            else if (p2 == -1) nums1[cur --] = nums1[p1 --];
            else if(nums1[p1] > nums2[p2]) nums1[cur --] = nums1[p1 --];
            else nums1[cur --] = nums2[p2 --];
        }
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 69.99%    O(n) = m + n
MEMORY: 8.9MB    BEAT: 63.39%    O(n) = 1
LAST EDIT TIME: 2021年3月8日15:7:37
Description: 双指针。从后向前遍历。可以在原数组上进行修改，不用开辟新的空间。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int cur;
        int cur = n + m -1;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) cur = nums2[p2 --];
            else if (p2 == -1) cur = nums1[p1 --];
            else if (nums1[p1] < nums2[p2]) cur = nums2[p2 --];
            else cur = nums1[p1 --];
            nums1[cur --] = cur;
        }
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = m + n
MEMORY: 8.7MB    BEAT:  94.18%    O(n) = m + n
LAST EDIT TIME: 2021年3月8日14:58:58
Description: 双指针。需要新开辟一个m+n长度的数组用于存储。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int ans[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) cur = nums2[p2 ++];
            else if (p2 == n) cur = nums1[p1 ++];
            else if (nums1[p1] < nums2[p2]) cur = nums1[p1 ++];
            else cur = nums2[p2 ++];
            ans[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i < n + m; i ++) {
            nums1[i] = ans[i];
        }
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 16.14%    O(n) = (m+n)log(m+n)
MEMORY: 8.8MB    BEAT: 86.77%    O(n) = log(m+n)
USED TIME: 06:26
LAST EDIT TIME: 2021年3月8日14:50:24
Description: 直接合并后排序。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < nums1.size(); i ++) nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.end());
    }
};

// @lc code=end
