/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-08 16:18:55
 * @LastEditTime: 2021-03-08 16:57:20
 * @FilePath: \Leetcode\759.Employee Free Time.cpp
 */


// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};


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
#include <map>
using namespace std;


/*
RESULT: Accept
TIME:     36ms    BEAT: 86.00%    O(n) = 
MEMORY: 10.2MB    BEAT: 84.00%    O(n) = 
LAST EDIT TIME: 2021年3月8日16:57:26
Description: 参考别人的代码和思路，自己写的。
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all;

        for (auto &person: schedule) {
            for (auto &interval: person) {
                all.push_back(interval);
            }
        }

        sort(all.begin(), all.end(), [](const Interval& x, const Interval& y) {
            return x.start < y.start;
        });

        vector<Interval> ans;
        int end = all[0].end;

        for (auto &busy: all) {
            if (busy.start > end) ans.emplace_back(end, busy.start);
            end = max(end, busy.end);
        }

        return ans;
    }
};
