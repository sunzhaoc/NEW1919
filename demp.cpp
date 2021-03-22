/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-21 21:43:30
 * @LastEditTime: 2021-03-21 21:57:33
 * @FilePath: \Leetcode\demp.cpp
 */
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

class Solution {
public:
    int isPalindrome(int x) {
        int res;
        while (x) {
            if (x == 1) {
                x --;
                res ++;
            }
            else if (x % 6 == 0) {
                if (x / 3 < x - 1) {
                    x /= 3;
                    res ++;
                }
                else if (x / 2 < x - 1) {
                    x /= 2;
                    res ++;
                }
                else {
                    x --;
                    res ++;
                }
            }
            else if (x % 3 == 0) {
                x = x / 3 < x - 1 ? x / 3 : x - 1;
                res ++;
            }
            else if (x % 2 == 0) {
                x = x / 2 < x - 1 ? x / 2 : x - 1;
                res ++;
            }
            else {
                res ++;
                x --;
            }


        }

        return res;
    }
};



int main() {
    Solution sol;
    for (int i = 1; i < 50; i ++) {
    int ans = sol.isPalindrome(i);
    cout << i << " " << ans << endl;
    }
    system("pause");
    return 0;
}
