/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 09:10:56
 * @LastEditTime: 2021-01-05 09:24:30
 * @FilePath: \Leetcode\830.Positions of Large Groups.cpp
 */
/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 7.7MB    BEAT:  33.85%    O(n) = 1
USED TIME: 13:06
Description: 
*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int start = 0, end = 0;
        vector<vector<int>> ans;
        for (int i  = 1; i < s.length(); i ++) {
            if (s[i] == s[i - 1]) {
                end = i;
                if (i == s.length() - 1 && end - start >= 2) ans.push_back({start, end});
            }
            else if (end - start >= 2) {
                ans.push_back({start, end});
                start = i;
                end = i;
            }
            else {
                start = i;
                end = i;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // vector<vector<int>> ans = sol.largeGroupPositions("abbxxxxzzy");
    // vector<vector<int>> ans = sol.largeGroupPositions("abcdddeeeeaabbbcd");
    // vector<vector<int>> ans = sol.largeGroupPositions("aaa");
    vector<vector<int>> ans = sol.largeGroupPositions("aa");
    // cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

