/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-01 15:20:23
 * @LastEditTime: 2021-04-01 15:59:13
 * @FilePath: \Leetcode\874.Walking Robot Simulation.cpp
 */
/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
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
TIME:    148ms    BEAT: 49.53%    O(n) = 
MEMORY: 50.1MB    BEAT:  5.05%    O(n) = 
USED TIME: 33:42
LAST EDIT TIME: 2021年4月1日15:56:18
Description: 二刷。前一次是python。
这根本不是Easy題。草。
不能设置成unordered_set<pair<int,int>>，C++不支持pair<int, int> 的哈希。如果用只能重写hash函数。所以官解是错的。
只能用unordered_map<int, unordered_set<int>> 的形式。
气死。
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res = 0;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0;
        int dir = 0;
        unordered_map<int, unordered_set<int>> map; // 这条重点。

        for (auto it: obstacles) map[it[0]].insert(it[1]);
        
        
        for (int command: commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
            }
            else if (command == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                for (int i = 0; i < command; i ++) {
                    if (map.find(x + dx[dir]) != map.end() && map[x + dx[dir]].count(y + dy[dir])) {
                        continue;
                    }
                    else {
                        x += dx[dir];
                        y += dy[dir];
                        res = max(res, x * x + y * y);
                    }
                }
            }
        }
        return res;
    }
};



// @lc code=end

