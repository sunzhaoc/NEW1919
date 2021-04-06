/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-15 20:34:24
 * @LastEditTime: 2020-12-15 20:39:22
 * @FilePath: \Leetcode\剑指 Offer 10- II. 青蛙跳台阶问题.cpp
 */

#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
Description: 
*/

class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1;
        for (int i = 0; i < n; i ++) {
            a = b;
            b = (a + b) % 1000000007;
        }
        return a;
    }
};


int main() {
    Solution sol;
    int ans = sol.numWays(3);
    system("pause");
    return 0;
}