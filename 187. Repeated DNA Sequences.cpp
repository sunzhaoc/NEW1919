/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 18:31:42
 * @LastEditTime: 2021-03-18 18:42:45
 * @FilePath: \Leetcode\187.Repeated DNA Sequences.cpp
 */
/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
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
TIME:     56ms    BEAT: 88.70%    O(n) = 
MEMORY: 22.9MB    BEAT: 28.84%    O(n) = 
USED TIME: 07:43
LAST EDIT TIME: 2021年3月18日18:42:51
Description: Easy 哈希。
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10) return {};
        unordered_map<string, int> map;
        vector<string> res;
        for (int i = 0; i < s.length() - 10 + 1; i ++) {
            map[s.substr(i, 10)] ++;
        }
        for (auto i = map.begin(); i != map.end(); i ++) {
            if (i->second > 1) res.emplace_back(i->first);
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<string> ans = sol.findRepeatedDnaSequences("AAAAAAAAAAA");
    
    system("pause");
    return 0;
}

// @lc code=end

