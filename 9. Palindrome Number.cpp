/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 21:34:02
 * @LastEditTime: 2021-03-09 21:40:54
 * @FilePath: \Leetcode\9.Palindrome Number.cpp
 */
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
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
TIME:    24ms    BEAT: 23.64%    O(n) = logn
MEMORY: 5.9MB    BEAT: 51.61%    O(n) = 1
USED TIME: 03:59
LAST EDIT TIME: 2021年3月9日21:40:17
Description: 
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int a = x;
        long long tmp = 0;
        while (a) {
            tmp = tmp * 10 + (a % 10);
            a = a / 10;
        }
        return tmp == x ? true : false;
    }
};

// @lc code=end

