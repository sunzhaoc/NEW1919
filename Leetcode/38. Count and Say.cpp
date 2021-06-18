/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-18 20:58:50
 * @LastEditTime: 2021-03-18 21:21:39
 * @FilePath: \Leetcode\38.Count and Say.cpp
 */
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
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
TIME:   16ms    BEAT: 26.46%    O(n) = 
MEMORY:  7MB    BEAT: 26.56%    O(n) = 
USED TIME: 13:14
LAST EDIT TIME: 2021年3月18日21:19:14
Description: 
*/

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i ++) {
            deque<pair<char, int>> q;
            for (int j = 0; j < s.length(); j ++) {
                if (q.empty() || s[j] != q.back().first) q.push_back({s[j], 1});
                else q.back().second ++;
            }
            s = "";
            while (q.size()) {
                s += to_string(q.front().second) + q.front().first;
                q.pop_front();
            }
        }
        return s;
    }
};


int main() {
    Solution sol;
    string ans = sol.countAndSay(4);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

