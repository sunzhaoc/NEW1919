/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-08 18:46:03
 * @LastEditTime: 2021-03-08 18:49:22
 * @FilePath: \Leetcode\252.Meeting Rooms.cpp
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


/*
RESULT: Accept
TIME:     20ms    BEAT: 83.63%    O(n) = nlogn
MEMORY: 11.5MB    BEAT: 59.29%    O(n) = logn
USED TIME: 01:52
LAST EDIT TIME: 2021年3月8日18:48:43
Description: 
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};
