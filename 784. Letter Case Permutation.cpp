/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-04 15:23:44
 * @LastEditTime: 2021-01-04 16:51:13
 * @FilePath: \Leetcode\784.Letter Case Permutation.cpp
 */
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


/*
RESULT: Accept
TIME:   12ms    BEAT: 67.75%    O(n) = 
MEMORY: 12MB    BEAT: 20.38%    O(n) = 
USED TIME: 52:31
Description: 递归 + 优化。
*/

class Solution {
public:
    vector<string> ans;

    void backTrack(string& s, int index, string& sub_str) {
        if (sub_str.length() == s.length()) {
            ans.push_back(sub_str);
            return;
        }
        
        if (s[index] >= '0' && s[index] <= '9') {
            sub_str.push_back(s[index]);
            backTrack(s, index + 1, sub_str);            
            sub_str.pop_back();
        }

        else {
            sub_str.push_back(tolower(s[index]));
            backTrack(s, index + 1, sub_str);
            sub_str.pop_back();
            sub_str.push_back(toupper(s[index]));
            backTrack(s, index + 1, sub_str);
            sub_str.pop_back();
        }

        return;
    }

    vector<string> letterCasePermutation(string S) {
        string sub_str = "";
        backTrack(S, 0, sub_str);
        return ans;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 67.75%    O(n) = 
MEMORY: 12.4MB    BEAT:  8.34%    O(n) = 
USED TIME: 52:31
Description: 递归
*/

// class Solution {
// public:
//     vector<string> ans;

//     void backTrack(string& s, int index, string sub_str) {
//         if (sub_str.length() == s.length()) {
//             ans.push_back(sub_str);
//             return;
//         }
        
//         if (s[index] >= '0' && s[index] <= '9') {
//             backTrack(s, index + 1, sub_str + s[index]);            
//         }

//         else if (s[index] >= 'a' && s[index] <= 'z') {
//             backTrack(s, index + 1, sub_str + char(toupper(s[index])));
//             backTrack(s, index + 1, sub_str + s[index]);
//         }

//         else if (s[index] >= 'A' && s[index] <='Z') {
//             backTrack(s, index + 1, sub_str + char(tolower(s[index])));
//             backTrack(s, index + 1, sub_str + s[index]);
//         }

//         return;
//     }

//     vector<string> letterCasePermutation(string S) {
//         string sub_str = "";
//         backTrack(S, 0, sub_str);
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<string> ans = sol.letterCasePermutation("a1b2");
    // vector<string> ans = sol.letterCasePermutation("3z4");
    // vector<string> ans = sol.letterCasePermutation("12345");
    // vector<string> ans = sol.letterCasePermutation("C");
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}

// @lc code=end

