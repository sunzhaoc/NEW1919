/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 21:00:27
 * @LastEditTime: 2021-03-19 14:47:41
 * @FilePath: \Leetcode\6.z-字形变换.cpp
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
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
TIME:     16ms    BEAT: 42.57%    O(n) = 
MEMORY: 10.4MB    BEAT: 55.56%    O(n) = 
USED TIME: 07:36
LAST EDIT TIME: 2021年3月19日14:47:10
Description: 
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> map(numRows);
        int i = 0;
        while (1) { 
            for (int j = 0; j < numRows; j ++) {
                map[j] += s[i];
                i ++;
                if (i >= s.length()) break;
            }
            if (i >= s.length()) break;
            for (int j = numRows - 2; j > 0; j --) {
                map[j] += s[i];
                i ++;
                if (i >= s.length()) break;
            }
            if (i >= s.length()) break;
        }
        string res;
        for (int i = 0; i < numRows; i ++) res += map[i];
        return res;
    }
};


// @lc code=end

