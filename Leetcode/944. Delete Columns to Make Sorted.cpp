/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 16:09:52
 * @LastEditTime: 2021-04-01 16:16:58
 * @FilePath: \Leetcode\944.Delete Columns to Make Sorted.cpp
 */
/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
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
TIME:     56ms    BEAT: 35.75%    O(n) = 
MEMORY: 11.8MB    BEAT: 64.60%    O(n) = 
USED TIME: 04:57
LAST EDIT TIME: 2021年4月1日16:16:22
Description: 二刷。前一次是python。Easy.
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> tmp;
        int res = 0;
        for (int j = 0; j < strs[0].size(); j ++) {
            for (int i = 0; i < strs.size(); i ++) {
                tmp.push_back(strs[i][j]);
            }
            res = is_sorted(tmp.begin(), tmp.end()) ? res : res + 1;
            tmp.clear();
        }
        return res;
    }
};


// @lc code=end

