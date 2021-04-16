/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 15:31:56
 * @LastEditTime: 2021-03-08 15:59:28
 * @FilePath: \Leetcode\986.Interval List Intersections.cpp
 */
/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
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
TIME:     36ms    BEAT: 89.14%    O(n) = m + n
MEMORY: 18.1MB    BEAT: 92.05%    O(n) = m + n
USED TIME: 23:08
LAST EDIT TIME: 2021年3月8日15:55:53
Description: 交替。
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0) return {};
        vector<vector<int>> ans;
        int id1 = 0, id2 = 0;
        int low, high;
        while (id1 < firstList.size() && id2 < secondList.size()) {
            low = max(firstList[id1][0], secondList[id2][0]);
            high = min(firstList[id1][1], secondList[id2][1]);
            if (low <= high) ans.push_back({low, high});
            if (firstList[id1][1] < secondList[id2][1]) id1 ++;
            else id2 ++;
        }
        return ans;
    }
};

// @lc code=end

