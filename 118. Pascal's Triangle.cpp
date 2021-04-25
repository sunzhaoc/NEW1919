/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-07 13:50:44
 * @LastEditTime: 2020-12-14 22:08:44
 * @FilePath: \Leetcode\118.Pascal's Triangle.cpp
 */
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 35.46%    O(n) = n^2
MEMORY: 6.7MB    BEAT: 33.65%    O(n) = 1
Description: 
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)   return {};
        if (numRows == 1)   return {{1}};
        if (numRows == 2)   return {{1}, {1, 1}};

        vector<vector<int>> ans = {{1}, {1, 1}};
        for (int row = 3; row < numRows + 1; row ++){
            ans.push_back({});
            ans[row - 1].resize(row);
            ans[row - 1][0] = ans[row - 1][row - 1] = 1;
            for (int i = 0; i < row - 2; i ++){
                ans[row - 1][1 + i] = ans[row - 2][i] + ans[row - 2][i + 1];
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
    system("pause");
    return 0;
}
// @lc code=end

