/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-20 17:19:53
 * @LastEditTime: 2021-01-20 20:22:55
 * @FilePath: \Leetcode\718.Maximum Length of Repeated Subarray.cpp
 */
/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     440ms    BEAT: 45.40%    O(n) = 
MEMORY: 106.4MB    BEAT: 57.61%    O(n) = 
LAST EDIT TIME: 2021年1月20日20:22:41
Description: DP
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len_A = A.size();
        int len_B = B.size();
        int ans = 0;
        vector<vector<int>> dp(len_A + 1, vector<int>(len_B + 1, 0));
        for (int i = 0; i < len_A; i ++) {
            for (int j = 0; j < len_B; j ++) {
                dp[i + 1][j + 1] = A[i] == B[j] ? dp[i][j] + 1 : 0;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> A = {3,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    int ans = sol.findLength(A, B);
    cout << ans << endl; 
    system("pause");
    return 0;
}
// @lc code=end

