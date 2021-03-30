/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 16:24:03
 * @LastEditTime: 2021-03-30 17:05:43
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {

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

