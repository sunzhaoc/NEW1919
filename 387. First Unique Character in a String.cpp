/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-23 16:30:04
 * @LastEditTime: 2020-12-23 19:34:34
 * @FilePath: \Leetcode\387.First Unique Character in a String.cpp
 */
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:   152ms    BEAT: 25.24%    O(n) = n
MEMORY:  11MB    BEAT: 14.99%    O(n) = <=26
Description: 使用哈希表存储索引。这方法其实没什么必要。。。
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
        for (int i = 0; i < s.length(); i ++) {
            if (dict.count(s[i])) dict[s[i]] = -1;
            else dict[s[i]] = i;
        }
        
        int first = s.length();
        for (auto [_, pos]: dict) {
            if (pos != -1 && pos < first)   first = pos;
        }
        
        if (first == s.length()) return -1;
        return first;
    }
};


/*
RESULT: Accept
TIME:    108ms    BEAT: 48.22%    O(n) = n
MEMORY: 10.8MB    BEAT: 33.78%    O(n) = <=26
Description: 哈希表。使用哈希表存储频数。
*/

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         unordered_map<char, int> dict;
//         for (char ch: s) {
//             dict[ch] ++;
//         }
//         for (int i = 0; i < s.length(); i ++) {
//             if (dict[s[i]] == 1)    return i;
//         }
//         return -1;
//     }
// };


int main() {
    Solution sol;
    int ans = sol.firstUniqChar("leetcode");
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

