/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-11 09:28:30
 * @LastEditTime: 2021-03-11 10:08:00
 * @FilePath: \Leetcode\139.Word Break.cpp
 */
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
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



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

    }
};


/*
RESULT: Accept
TIME:     32ms    BEAT: 16.99%    O(n) = 
MEMORY: 13.1MB    BEAT: 36.11%    O(n) = 
USED TIME: 34:39
LAST EDIT TIME: 2021年3月11日10:6:38
Description: 记忆化回溯。
*/

class Solution {
public:
    unordered_set<string> dict;
    vector<int> memory;
    int n;

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memory.resize(n, -1);

        for (string s: wordDict) {
            dict.insert(s);
        }

        return backTrack(s, 0);
    }

    bool backTrack(string& s, int start) {
        if (start >= n) return true;

        if (memory[start] != -1) return memory[start];
        for (int i = start; i < n; i ++) {
            if (dict.find(s.substr(start, i - start + 1)) != dict.end() && backTrack(s, i + 1)) { 
                memory[start] = 1;
                return true;
            }
        }
        memory[start] = 0;
        return false;
    }
};


int main() {
    Solution sol;
    // vector<string> wordDict = {"leet", "code"};
    // bool ans = sol.wordBreak("leetcode", wordDict);
    vector<string> wordDict = {"aaaa", "aaa"};
    bool ans = sol.wordBreak("aaaaaab", wordDict);
    cout << ans << endl;
    system("pause");
    return 0;
}


// @lc code=end

