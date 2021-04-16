/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <sstream>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 7.3MB    BEAT:   6.57%    O(n) = 
USED TIME: 28:12
Description: 递归。
*/

class Solution {
public:
    vector<string> res;

    void caculateTime(vector<int> choose) {
        int hour = 0, min = 0;
        for (int i = 0; i < choose.size(); i ++){
            // Hour
            if (choose[i] < 4) {
                hour += pow(2, 3 - choose[i]);
            }

            // Min
            else min += pow(2, 9 - choose[i]);
        } 
        if (hour <= 11 && min <= 59) {
            if (min < 10) res.push_back(to_string(hour) + ":0" + to_string(min));
            else res.push_back(to_string(hour) + ":" + to_string(min));
        }
    }

    void backTrack(int num, int index, vector<int>& choose) {
        if (num == 0) {
            caculateTime(choose);
            return;
        }
        
        for (int i = index; i < 10; i ++) {
            choose.push_back(i);
            backTrack(num - 1, i + 1, choose);
            choose.pop_back();
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<int> choose;
        backTrack(num, 0, choose);
        return res;
    }
};


int main() {
    Solution sol;
    vector<string> ans = sol.readBinaryWatch(3);
    system("pause");
    return 0;
}
// @lc code=end

