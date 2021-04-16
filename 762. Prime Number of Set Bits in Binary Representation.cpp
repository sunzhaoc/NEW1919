/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-04 21:19:11
 * @LastEditTime: 2021-03-04 21:50:55
 * @FilePath: \Leetcode\762.Prime Number of Set Bits in Binary Representation.cpp
 */
/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:    44ms    BEAT: 28.92%    O(n) = 
MEMORY: 6.1MB    BEAT: 51.35%    O(n) = 
LAST EDIT TIME: 
Description: 
*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> list({2,3,5,7,11,13,17,19});

        int ans = 0;
        for (int i = L; i <= R; i ++) {
            int s = 0;
            for (int k = i; k; k >>= 1) s += k & 1;  // 快速计算一个二进制里有多少个1.
            if (list.count(s)) ans ++;
        }

        return ans;
    }
};


/*
RESULT: Accept
TIME:    16ms    BEAT: 48.43%    O(n) = nlogn
MEMORY: 5.9MB    BEAT: 68.61%    O(n) = 1
USED TIME: 14:00
LAST EDIT TIME: 2021年3月4日21:34:5
Description: 
*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for (int i = L; i <= R; i ++) {
            int x = i;
            int num = 0;
            while (x != 0) {
                num ++;
                x = x - (x & (-x));
            }
            if (isZhishu(num)) ans ++;
        }
        return ans;
    }

    bool isZhishu(int x) {
        if (x == 1) return false;
        if (x == 2) return true;
        for (int i = 2; i < x; i ++) {
            if (x % i == 0) return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    int ans = sol.countPrimeSetBits(6, 10);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

