/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-11 20:34:52
 * @LastEditTime: 2021-03-11 21:19:56
 * @FilePath: \Leetcode\279.Perfect Squares.cpp
 */
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年3月11日21:10:13
Description: BUG？超级大BUG？这里能过，Leetcode报错？草？这和322题有什么区别？
*/

class Solution {
public:
    int maxNum;
    vector<int> count;
    int numSquares(int n) {
        maxNum = sqrt(n);
        count.resize(n + 1, 0);
        return backTrack(n);
    }

    int backTrack(int remain) {
        if (remain == 0) return 0;
        if (remain == -1) return -1;

        if (count[remain] != 0) return count[remain];

        int Min = INT_MAX;
        for (int i = 1; i <= maxNum; i ++) {
            int res = backTrack(remain - i * i);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[remain] = Min == INT_MAX ? -1 : Min;
        return count[remain];
    }
};


int main() {
    Solution sol;
    int ans = sol.numSquares(1000);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

