/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-14 10:12:40
 * @LastEditTime: 2021-03-15 17:08:30
 * @FilePath: \Leetcode\1790.Check if One String Swap Can Make Strings Equal.cpp
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



/*
RESULT: Accept
TIME:     72ms    BEAT: 100.00%    O(n) = n^2?
MEMORY: 36.4MB    BEAT: 100.00%    O(n) = 
Description: bartsun大佬的代码。
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        for (int i = 0; i < s1.size(); i ++) {
            for (int j = 0; j < s1.size(); j ++) {
                string t = s1;
                swap(t[i], t[j]);
                if (t == s2) return true;
            }
        }
        return false;
    }
};


/*
RESULT: Accept
Description: 周赛写的。
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() == 1)  return false;
        vector<int> dp;
        for (int i = 0; i < s1.size(); i ++) {
            if (s1[i] != s2[i]) {
                dp.push_back(i);
                if (dp.size() == 2) {
                    if (s1[dp[0]] != s2[dp[1]] || s1[dp[1]] != s2[dp[0]]) return false;
                }
                if (dp.size() > 2) return false;
            }
        }
        if (dp.size() == 1) return false;
        return true;
        
    }
};


int main() {
    Solution sol;
    // bool ans = sol.areAlmostEqual("bank", "kanb");
    // bool ans = sol.areAlmostEqual("attack", "defend");
    // bool ans = sol.areAlmostEqual("kelb", "kelb");
    bool ans = sol.areAlmostEqual("aaab", "aaaa");
    cout << ans << endl;
    // cout << ans << endl;
    system("pause");
    return 0;
}

