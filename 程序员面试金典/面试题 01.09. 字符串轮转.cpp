/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-15 23:35:07
 * @LastEditTime: 2021-03-16 08:44:16
 * @FilePath: \Leetcode\demo.cpp
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 04:21
LAST EDIT TIME: 2021年3月16日8:43:26
Description: 两个字符串拼接在一起。使用find函数。我没想到string还有find。。。
*/

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        s1 += s1;
        return s1.find(s2) == string::npos ? false : true;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 16.27%    O(n) = 
MEMORY: 19.2MB    BEAT:  8.44%    O(n) = 
USED TIME: 07:25
LAST EDIT TIME: 2021年3月15日23:49:53
Description: 下面一种的优化，但还是需要多次子串判断。就是优化了当遇到元素相等时才进行子串的判断。
*/

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        for (int i = 0; i < s1.length(); i ++) {
            if (s1[i] == s2[0]) {
                string tmp1 = s1.substr(i, s1.length() - i - 1) + s1.substr(0, i);
                if (s1.substr(i, s1.length() - i) + s1.substr(0, i) == s2) return true;
            }
        }
        return false;
    }
};


/*
RESULT: Time Out
USED TIME: 05:35
LAST EDIT TIME: 2021年3月15日23:41:18
Description
*/

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        for (int i = 0; i < s1.length(); i ++) {
            if (s1 == (s2.substr(i, s2.length() - i) + s2.substr(0, i))) return true;
        }
        return false;
    }
};


int main() {
    Solution sol;
    bool ans = sol.isFlipedString("waterbottle", "erbottlewat");
    cout << ans << endl;
    system("pause");
    return 0;
}
