/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-08 18:49:47
 * @LastEditTime: 2021-03-08 19:12:52
 * @FilePath: \Leetcode\253.Meeting Rooms II.cpp
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
TIME:     20ms    BEAT: 89.58%    O(n) = 
MEMORY: 11.4MB    BEAT: 73.03%    O(n) = 
LAST EDIT TIME: 2021年3月8日19:12:34
Description: 最小堆
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        
        priority_queue<int, vector<int>, greater<int>> minHeap_room;
        sort(intervals.begin(), intervals.end());
        
        minHeap_room.push(intervals[0][1]);
        for (int i = 1; i < n; i ++) {
            if (intervals[i][0] >= minHeap_room.top()) {
                minHeap_room.pop();
                minHeap_room.push(intervals[i][1]);
            }
            else {
                minHeap_room.push(intervals[i][1]);
            }
        }
        return minHeap_room.size();
    }
};


/*
RESULT: Accept
TIME:     92ms    BEAT: 21.11%    O(n) = 
MEMORY: 36.1MB    BEAT:  5.04%    O(n) = 
LAST EDIT TIME: 2021年3月8日19:4:9
Description: 稍微优化了一下。
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int startTime = intervals[0][0];
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] > y[1];
        });
        int endTime = intervals[0][1];

        vector<int> diff(endTime - startTime + 1, 0);
        for (auto it: intervals) {
            int start = it[0], end = it[1];
            diff[start - startTime] ++;
            diff[end - startTime] --;
        }

        for (int i = 1; i < diff.size(); i ++) {
            diff[i] += diff[i - 1];
        }
        return *max_element(diff.begin(), diff.end());
    }
};



/*
RESULT: Accept
TIME:     856ms    BEAT: 5.28%    O(n) = 
MEMORY: 291.6MB    BEAT: 5.04%    O(n) = 
LAST EDIT TIME: 2021年3月8日18:56:37
Description: 差分。
*/

// class Solution {
// public:
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         vector<int> diff(1000001, 0);
//         for (auto it: intervals) {
//             int start = it[0], end = it[1];
//             diff[start] ++;
//             diff[end] --;
//         }

//         for (int i = 1; i < 1000001; i ++) {
//             diff[i] += diff[i - 1];
//         }
//         return *max_element(diff.begin(), diff.end());
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> nums = {{0,30}, {5,10}, {15, 20}};
    int ans = sol.minMeetingRooms(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}

