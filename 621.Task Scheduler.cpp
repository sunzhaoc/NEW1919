/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-31 16:43:24
 * @LastEditTime: 2021-03-31 17:04:24
 * @FilePath: \Leetcode\621.Task Scheduler.cpp
 */
/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
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
USED TIME: 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> time(26);
        struct cmp
        {
            bool operator() (const pair<char, int>& x, const pair<char, int>& y) {
                return x.second < y.second;
            }
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> q;
        unordered_map<char, int> map;
        for (char& task: tasks) map[task] ++;
        for (auto it = map.begin(); it != map.end(); it ++) {
            q.push({it->first, it->second});
        }

        int cnt = 0;
        
    }
};
// @lc code=end

