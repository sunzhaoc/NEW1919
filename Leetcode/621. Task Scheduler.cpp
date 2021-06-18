/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-31 16:43:24
 * @LastEditTime: 2021-03-31 18:30:16
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
TIME:     56ms    BEAT: 98.00%    O(n) = 
MEMORY: 33.6MB    BEAT: 79.82%    O(n) = 
LAST EDIT TIME: 2021年3月31日18:30:4
Description: 桶思想。很值得做一做。
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> vec(26);
        for (char c: tasks) vec[c - 'A'] ++;
        sort(vec.rbegin(), vec.rend());
        int cnt = 1;
        //-----------这两句很关键。---------
        while (cnt < vec.size() && vec[cnt] == vec[0]) cnt ++;
        return max(len, cnt + (n + 1) * (vec[0] - 1)); 
        //---------------------------------
    }
};


/*
RESULT: Accept
TIME:    144ms    BEAT: 19.72%    O(n) = 
MEMORY: 33.7MB    BEAT: 37.65%    O(n) = 
USED TIME: 挺长。
LAST EDIT TIME:  2021年3月31日17:52:21
Description: 二刷。前一次是python。
双最大堆。
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n ++;
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
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> qtmp;

        int cnt = 0;
        while (q.size() || qtmp.size()) {
            if (cnt % n != 0) {
                if (q.size()) {
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
                auto it = q.top();
                q.pop();
                it.second --;
                if (it.second) qtmp.push(it);
                cnt ++;
            }
        }
        return cnt;
    }
};


int main() {
    Solution sol;
    vector<char> nums = {'A','A','A','B','B','B','A','A','A','B','B','B','C','C','D','D','D','F','F'};
    int ans = sol.leastInterval(nums, 2);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

