/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 16:11:35
 * @LastEditTime: 2021-03-03 16:37:57
 * @FilePath: \Leetcode\249.Group Shifted Strings.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <typeinfo>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 91.78%    O(n) = 
MEMORY: 7.8MB    BEAT: 75.00%    O(n) = 
USED TIME: 24:16
LAST EDIT TIME: 2021年3月3日16:36:31
Description: 
难点在于“字母表首尾相接”。
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> dict;
        for (string& str: strings) {
            if (str.length() == 1) dict["-1"].emplace_back(str);
            else {
                string tmp;
                for (int i = 1; i < str.length(); i ++) {
                    tmp += to_string(str[i] - str[i - 1] < 0 ? 26 + str[i] - str[i - 1] : str[i] - str[i - 1]);
                    tmp += " ";    // 不加这个的话容易出错。
                }
                dict[tmp].emplace_back(str);
            }
        }

        vector<vector<string>> ans;
        for (auto it = dict.begin(); it != dict.end(); it ++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<string> strings = {"az", "ba", "abc", "bcd", "acef", "xyz", "a", "z"};
    auto ans = sol.groupStrings(strings);
    system("pause");
    return 0;
}
