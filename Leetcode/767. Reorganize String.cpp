/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 09:43:51
 * @LastEditTime: 2021-04-01 13:32:42
 * @FilePath: \Leetcode\767.Reorganize String.cpp
 */
/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT:  35.80%    O(n) = 
LAST EDIT TIME: 2021年4月1日13:32:33
Description: 优化了一下。
*/

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> map;
        for (auto s: S) map[s] ++;
        
        struct cmp
        {
            bool operator() (const pair<char, int>& x, const pair<char, int>& y) {
                return x.second < y.second;
            }
        };

        string res = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> q;
        for (auto it = map.begin(); it != map.end(); it ++) {
            q.push({it->first, it->second});
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> qtmp;
        int n = 2;
        int cnt = 0;
        while (q.size() || qtmp.size()) {
            if (cnt % n != 0) {
                if (q.size()) {
                    res += q.top().first;
                    auto it = q.top();
                    q.pop();
                    it.second --;
                    if (it.second)  qtmp.push(it);
                    cnt ++;
                }
                else {
                    cnt ++;
                }
            }
            else {
                while (qtmp.size()) {
                    q.push(qtmp.top());
                    qtmp.pop();
                }
                res += q.top().first;
                auto it = q.top();
                q.pop();
                it.second --;
                if (it.second) qtmp.push(it);
            }
            if (res.size()> 1 && res[res.size() - 1] == res[res.size() - 2]) return "";
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     8ms    BEAT:  8.12%    O(n) = 
MEMORY: 6.3MB    BEAT: 26.67%    O(n) = 
USED TIME: About 1 hour.
LAST EDIT TIME: 2021年4月1日11:7:3
Description: 与621題的核心代码相同。昨天刚写的，就不知道咋写了。直接copy的。这个方法有点复杂。
*/

class Solution {
public:
    string reorganizeString(string S) {
        vector<pair<char, int>> map;
        sort(S.begin(), S.end());
        int l = 0, r = 0;
        while (r < S.length()) {
            if (S[r] == S[l]) {
                if (r == S.length() - 1) {
                    map.push_back({S[l], r- l + 1});
                    break;
                }
                r ++;
            }
            else if (S[r] != S[l]) {
                map.push_back({S[l], r - l});
                if (r ==  S.size() - 1) {
                    map.push_back({S[r], 1});
                    break;
                }
                l = r;
                r ++;
            }
        }
        sort(map.begin(), map.end(), [](const pair<char, int>& x, const pair<char, int>& y) {
            return x.second < y.second;
        });
        
        if (map.size() == 1 && map[0].second > 1)  return "";

        struct cmp
        {
            bool operator() (const pair<char, int>& x, const pair<char, int>& y) {
                return x.second < y.second;
            }
        };
        string res = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> q;
        for (int i = 0; i < map.size(); i ++) q.push(map[i]);
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> qtmp;
        int n = 2;
        int cnt = 0;
        while (q.size() || qtmp.size()) {
            if (cnt % n != 0) {
                if (q.size()) {
                    res += q.top().first;
                    auto it = q.top();
                    q.pop();
                    it.second --;
                    if (it.second)  qtmp.push(it);
                    cnt ++;
                }
                else {
                    cnt ++;
                }
            }
            else {
                while (qtmp.size()) {
                    q.push(qtmp.top());
                    qtmp.pop();
                }
                res += q.top().first;
                auto it = q.top();
                q.pop();
                it.second --;
                if (it.second) qtmp.push(it);
                cnt ++;
            }
            if (res.size()> 1 && res[res.size() - 1] == res[res.size() - 2]) return "";
        }
        return res;
    }
};
// @lc code=end

