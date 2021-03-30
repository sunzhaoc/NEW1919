/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 16:24:03
 * @LastEditTime: 2021-03-30 19:14:01
 * @FilePath: \Leetcode\275.H-Index II.cpp
 */
/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
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
TIME:      8ms    BEAT: 99.90%    O(n) = 
MEMORY: 18.2MB    BEAT:  8.93%    O(n) = 
LAST EDIT TIME: 2021年3月30日18:57:22
Description: Y总。
*/

class Solution {
public:
    int hIndex(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[nums.size() - mid] >= mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }
}; 


/*
RESULT: Accept
TIME:     24ms    BEAT: 45.48%    O(n) = 
MEMORY: 18.1MB    BEAT: 18.69%    O(n) = 
LAST EDIT TIME: 2021年3月30日16:58:43
Description: 二分。二刷。前一次是python。很难。。。不会。
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        if (citations[n - 1] == 0) return 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (n - mid == citations[mid]) return n - mid; // n - mid 论文数
            if (n - mid < citations[mid]) r = mid;
            else l = mid + 1;
        }
        return n - l;
    }
};

// @lc code=end

