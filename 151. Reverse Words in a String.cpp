/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 20:59:14
 * @LastEditTime: 2021-03-19 10:01:02
 * @FilePath: \Leetcode\151.Reverse Words in a String.cpp
 */
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
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
TIME:     8ms    BEAT: 38.54%    O(n) = 
MEMORY: 7.6MB    BEAT: 34.14%    O(n) = 
USED TIME: 13:17
LAST EDIT TIME: 2021年3月19日9:43:48
Description: Easy
*/

class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        stack<string> ss;
        string res;
        while (r < s.length()) {
            while (s[l] == ' ') l ++;
            if (l >= s.length()) break;
            r = l;
            while (r + 1 < s.length() && s[r + 1] != ' ') r ++;
            ss.push(s.substr(l, r - l + 1));
            l = r + 1;
        }

        while (ss.size()) {
            res += ss.top();
            ss.pop();
            if (ss.size()) res += ' ';
        }

        return res;
    }
};


int main() {
    Solution sol;
    string ans = sol.reverseWords("the sky is blue");
    // string ans = sol.reverseWords("  hello world!  ");
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

