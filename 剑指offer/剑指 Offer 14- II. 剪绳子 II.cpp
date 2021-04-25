/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-18 15:09:28
 * @LastEditTime: 2020-12-18 16:02:34
 * @FilePath: \Leetcode\剑指 Offer 14- II. 剪绳子 II.cpp
 */

#include <iostream>
#include <math.h>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = log2(N)
MEMORY: 6.1MB    BEAT:  27.84%    O(n) = 1
Description: 快速求余法，二分求余法。
https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0) return modFunction(3, a);
        if (b == 1) return modFunction(3, a - 1) * 4 % 1000000007;
        return modFunction(3, a) * 2 % 1000000007;
    }

private:
    long modFunction(long x, int n) {
        long ans = 1;
        while (n > 0)
        {
            if (n % 2)  ans = (ans * x) % 1000000007;
            x = x * x % 1000000007;
            n /= 2;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = n
MEMORY: 6.1MB    BEAT:  27.84%    O(n) = 1
Description: 循环求余法。
*/

// class Solution {
// public:
//     int cuttingRope(int n) {
//         if (n <= 3) return n - 1;
//         int a = n / 3, b = n % 3;
//         if (b == 0) return modFunction(3, a);
//         if (b == 1) return modFunction(3, a - 1) * 4 % 1000000007;
//         return modFunction(3, a) * 2 % 1000000007;
//     }

// private:
//     long modFunction(int x, int n) {
//         long ans = 1;
//         for (int i = 0; i < n; i ++) {
//             ans = (ans * x) % 1000000007;
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    // int ans = sol.cuttingRope(4);
    int ans = sol.cuttingRope(54);
    cout << ans << endl;
    system("pause");
    return 0;
}
