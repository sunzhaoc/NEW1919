/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-01 09:15:33
 * @LastEditTime: 2021-04-01 09:40:41
 * @FilePath: \Leetcode\1006.Clumsy Factorial.cpp
 */
/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 5.8MB    BEAT:  83.64%    O(n) = 
USED TIME: 15:41
LAST EDIT TIME: 2021年4月1日9:40:0
Description: 四个为一组。不满一组的时候单独讨论。
*/

class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 6;
        if (N == 4) return 7;

        int a = N / 4;
        int b = N % 4;
        
        int sum = 0;
        for (int i = 0; i < a; i ++) {
            if (i == 0) sum +=N * (N - 1) / (N - 2) + (N - 3);
            else sum -=  N * (N - 1) / (N - 2) - (N - 3);
            N -= 4;
        }

        if (b == 0) return sum;
        if (b == 1) return sum - N;
        if (b == 2) return sum - N * (N - 1);
        return sum - N * (N - 1) / (N - 2);
    }
};

// @lc code=end

