/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-02 09:45:22
 * @LastEditTime: 2021-03-02 10:03:29
 * @FilePath: \Leetcode\22.Generate Parentheses.cpp
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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
using namespace std;


/*
RESULT: Accept
TIME:      4ms    BEAT: 75.30%    O(n) = 
MEMORY: 13.6MB    BEAT: 43.10%    O(n) = 
USED TIME: 13:36
LAST EDIT TIME: 2021年3月2日10:0:56
Description: 回溯。
*/

class Solution {
public:
    vector<string> ans;
    int L, R;

    vector<string> generateParenthesis(int n) {
        L = n;
        R = n;
        dfs(L, R, "");
        return ans;
    }
    
    void dfs(int L, int R, string s) {
        if (L == 0 && R == 0) {
            ans.emplace_back(s);
            return;
        }
        
        else if (L == R) {
            s += "(";
            L --;
            dfs(L, R, s);
        }

        else {
            if (L - 1 >= 0) dfs(L - 1, R, s + "(");
            if (R - 1 >= 0) dfs(L, R - 1, s + ")");
        }
    }
};


int main() {
    Solution sol;
    vector<string> ans = sol.generateParenthesis(3);
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl; 
    }
    system("pause");
    return 0;
}

// @lc code=end

