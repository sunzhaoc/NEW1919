/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-18 20:59:31
 * @LastEditTime: 2021-03-19 10:34:24
 * @FilePath: \Leetcode\165.Compare Version Numbers.cpp
 */
/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
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
TIME:   0ms    BEAT: 100.00%    O(n) = max(n, m)
MEMORY: 6MB    BEAT:  92.44%    O(n) = 1
USED TIME: 21:15
LAST EDIT TIME: 2021年3月19日10:25:10
Description: 双指针。Easy。
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = 0, l2 = 0;
        int v1 = 0, v2 = 0;
        while (1) {
            v1 = 0, v2 = 0;
            if (l1 < version1.length()) {
                while (version1[l1] == '0') l1 ++;
                while (l1 < version1.length() && version1[l1] != '.') {
                    v1 = v1 * 10 + version1[l1] - '0';
                    l1 ++;
                }
                l1 ++;
            }

            if (l2 < version2.length()) {
                while (version2[l2] == '0') l2 ++;
                while (l2 < version2.length() && version2[l2] != '.') {
                    v2 = v2 * 10 + version2[l2] -'0';
                    l2 ++;
                }
                l2 ++;
            }

            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;

            if (l1 > version1.length() && l2 > version2.length()) break;
        }
        return 0;
    }
};

// @lc code=end

