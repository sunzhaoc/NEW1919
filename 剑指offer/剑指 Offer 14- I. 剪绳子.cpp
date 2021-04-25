/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-18 14:36:19
 * @LastEditTime: 2020-12-18 15:09:11
 * @FilePath: \Leetcode\剑指 Offer 14- I. 剪绳子.cpp
 */
#include <iostream>
#include <math.h>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 1
MEMORY: 6.4MB    BEAT:  22.58%    O(n) = 1
Description: 数学推导。3比2好，尽量多的3，其次是2。
https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
仅有求整、求余、次方运算，
求整和求余运算：资料提到不超过机器数的整数可以看作是 O(1)，
幂运算：查阅资料，提到浮点取幂为 O(1)。
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0) return (int)pow(3, a);
        if (b == 1) return (int)pow(3, a - 1) * pow(2, 2);
        return (int)pow(3, a) * 2;
    }
};


int main() {
    Solution sol;
    int ans = sol.cuttingRope(10);
    cout << ans << endl;
    system("pause");
    return 0;
}
