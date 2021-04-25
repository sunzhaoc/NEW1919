/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 14:56:35
 * @LastEditTime: 2021-04-01 15:05:31
 * @FilePath: \Leetcode\852.Peak Index in a Mountain Array.cpp
 */
/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
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
TIME:     12ms    BEAT: 76.16%    O(n) = logn
MEMORY: 11.1MB    BEAT: 88.95%    O(n) = nlogn
USED TIME: 03:55
LAST EDIT TIME: 2021年4月1日15:5:4
Description: 二分。
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2;

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            else if (arr[mid] < arr[mid - 1]) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};


/*
RESULT: Accept
TIME:     16ms    BEAT: 41.28%    O(n) = n
MEMORY: 11.2MB    BEAT: 69.48%    O(n) = 1
USED TIME: 01:15
LAST EDIT TIME: 2021年4月1日14:59:6
Description: 二刷。之前是python。
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        for (int i = 1; i < arr.size() - 1; i ++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) return i;
        }
        return -1;
    }
};

// @lc code=end

