/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-08 19:20:01
 * @LastEditTime: 2021-03-08 20:05:24
 * @FilePath: \Leetcode\1094.Car Pooling.cpp
 */
/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
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
TIME:    12ms    BEAT: 70.91%    O(n) = 
MEMORY: 8.5MB    BEAT: 89.55%    O(n) = 
USED TIME: 07:15
LAST EDIT TIME: 2021年3月8日19:51:5
Description: 差分。
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        int startPos = trips[0][1];
        sort(trips.begin(), trips.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[2] > y[2];
        });
        int endPos = trips[0][2];

        vector<int> map(endPos - startPos + 1, 0);
        for (int i = 0; i < trips.size(); i ++) {
            map[trips[i][1] - startPos] += trips[i][0];
            map[trips[i][2] - startPos] -= trips[i][0];
        }
        for (int i = 1; i < map.size(); i ++) {
            map[i] += map[i - 1];
            if (map[i] > capacity) return false;
        }
        return true;
    }
};


/*
RESULT: Wrong
LAST EDIT TIME: 2021年3月8日19:42:54
Description: 
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>[1]>> minHeap_room; // 这步好像有问题。
        int nums = trips[0][0];
        minHeap_room.push({trips[0][0], trips[0][2]});
        for (int i = 1; i < trips.size(); i ++) {
            if (trips[i][1] >= minHeap_room.top()[1]) {
                nums = nums - minHeap_room.top()[0] + trips[i][0];
                minHeap_room.pop();
                minHeap_room.push({trips[i][0], trips[i][2]});
                if (nums > capacity) return false;
            }
            else {
                minHeap_room.push({trips[i][0], trips[i][2]});
                nums += trips[i][0];
                if (nums > capacity) return false;
            }
        }
        return true;
    }
};

// @lc code=end

