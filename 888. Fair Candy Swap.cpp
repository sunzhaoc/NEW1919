/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-02-01 19:12:20
 * @LastEditTime: 2021-02-01 19:44:36
 * @FilePath: \Leetcode\888.Fair Candy Swap.cpp
 */
/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <numeric>
#include <unordered_set>
using namespace std;

/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 
Description:   
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        vector<int> ans;
        for (auto& y : B) {
            int x = y + delta;
            if (rec.count(x)) {
                ans = vector<int>{x, y};
                break;
            }
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     84ms    BEAT: 98.76%    O(n) = 
MEMORY: 35,5MB    BEAT: 96.25%    O(n) = 
LAST EDIT TIME: 2021年2月1日19:40:57
Description: 双指针。
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        if (diff == 0) return {};
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int indexA = 0, indexB = 0;
        while (indexA < A.size() && indexB < B.size()) {
            if (A[indexA] - B[indexB] == diff) return {A[indexA], B[indexB]};
            else if (A[indexA] - B[indexB] > diff) {
                indexB ++;
            }
            else indexA ++;
        }
        return {};
    }
};

// @lc code=end

