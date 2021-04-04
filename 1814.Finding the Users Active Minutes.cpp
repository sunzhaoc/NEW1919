/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-04 10:06:52
 * @LastEditTime: 2021-04-04 14:48:19
 * @FilePath: \Leetcode\1814.Finding the Users Active Minutes.cpp
 */

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

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

/*
RESULT: Accept
Description: 比赛写的。
*/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> map;
        for (int i = 0; i < logs.size(); i ++) {
            map[logs[i][0]].insert(logs[i][1]);
        }
        unordered_map<int, int> times;
        for (auto it = map.begin(); it != map.end(); it ++) {
            times[it->second.size()] ++;
        }
        vector<int> res(k, 0);
        for (auto it = times.begin(); it != times.end(); it ++) {
            res[it->first - 1] = it->second;
        }
        return res;
    }
};

