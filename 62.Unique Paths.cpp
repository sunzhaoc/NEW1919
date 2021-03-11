/*
 * @Description:  
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-09 10:28:43
 * @LastEditTime: 2020-12-09 10:41:55
 * @FilePath: \Leetcode\62.不同路径.cpp
 */
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = m
MEMORY: 6.3MB    BEAT:  61.38%    O(n) = 1 
Description: 利用数学组合数知识解决。因为m，n可互换，利用这点可以降低运算时间。
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long sum_up = 1;
        long long sum_down = 1;

        int max = (n >= m)? n : m;
        int min = (n <= m)? n : m;
        for (int i = max; i < min + max - 2 + 1; i ++) {
            sum_up = i * sum_up;
        }
        for (int i = 1; i < min - 1 + 1; i ++) {
            sum_down = i * sum_down;
        }
        return sum_up / sum_down;
    }
};


int main() {
    Solution sol;
    int A = sol.uniquePaths(3, 2);
    cout << A << endl;
    system("pause");
    return 0;
}

// @lc code=end

