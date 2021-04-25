/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-11 13:44:38
 * @LastEditTime: 2021-03-11 14:06:55
 * @FilePath: \Leetcode\215.Kth Largest Element in an Array.cpp
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
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
TIME:     8ms    BEAT: 92.09%    O(n) = 
MEMORY: 9.9MB    BEAT: 33.40%    O(n) = 
LAST EDIT TIME: 2021年3月11日14:6:8
Description: 小顶堆。
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) return INT_MIN;

        int len = nums.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < k; i ++) {
            min_heap.push(nums[i]);
        }

        for (int i = k; i < len; i ++) {
            if (nums[i] >= min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }

        return min_heap.top();
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT: 92.09%    O(n) = nlogn
MEMORY: 9.7MB    BEAT: 81.20%    O(n) = logn
USED TIME: 02:09
LAST EDIT TIME: 2021年3月11日13:47:50
Description: 
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const int x, const int y) {return x > y;});
        return nums[k - 1];
    }
};

// @lc code=end

