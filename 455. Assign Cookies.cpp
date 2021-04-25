/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-25 09:52:49
 * @LastEditTime: 2020-12-25 10:15:13
 * @FilePath: \Leetcode\455.Assign Cookies.cpp
 */
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
RESULT: Accept
TIME:     84ms    BEAT: 79.18%    O(n) = n
MEMORY: 17.3MB    BEAT: 79.90%    O(n) = 1
Description: 
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int kid = 0;
        
        for (int i = 0; i < s.size(); i ++) {
            if (kid == g.size()) break;

            if (g[kid] <= s[i]) kid ++;
        }

        return kid;
    }
};


int main() {
    Solution sol;
    vector<int> g = {1, 2, 3}, s = {3};
    int ans = sol.findContentChildren(g, s);
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

