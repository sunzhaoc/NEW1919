/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-02 18:39:27
 * @LastEditTime: 2021-03-02 18:57:49
 * @FilePath: \Leetcode\896.Monotonic Array.cpp
 */
/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
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
TIME:     72ms    BEAT: 57.92%    O(n) = n
MEMORY: 48.4MB    BEAT: 47.10%    O(n) = 1
LAST EDIT TIME: 2021年3月2日18:56:33
Description: 利用了自带的is_sorted函数。
https://leetcode-cn.com/problems/monotonic-array/solution/dan-diao-shu-lie-by-leetcode-solution-ysex/
*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
    }
};


/*
RESULT: Accept
TIME:     72ms    BEAT: 57.92%    O(n) = n
MEMORY: 48.2MB    BEAT: 96.12%    O(n) = 1
USED TIME: 10:52
LAST EDIT TIME: 2021年3月2日18:51:46
Description: 遍历一次。
*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 2) return true;
        
        bool U = true, D = true;
        for (int i = 1; i < A.size(); i ++) {
            if (A[i] < A[i - 1] && U) U = false;    // 这个数组不是递增的
            if (A[i] > A[i - 1] && D) D = false;    // 不是递减的
        }

        return U || D;
    }
};

// @lc code=end

