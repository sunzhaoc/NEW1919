/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 15:22:27
 * @LastEditTime: 2021-03-18 21:27:58
 * @FilePath: \Leetcode\49.Group Anagrams.cpp
 */
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
using namespace std;


/*
RESULT: Accept
TIME:     52ms    BEAT: 76.29%    O(n) = 
MEMORY: 18.9MB    BEAT: 79.56%    O(n) = 
USED TIME: 02:14
LAST EDIT TIME: 二刷。
Description: 
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].emplace_back(s);
        } 

        vector<vector<string>> res;
        for (auto it = map.begin(); it != map.end(); it ++) {
            res.push_back(it->second);
        }
        return res;
    }
};

/*
RESULT: Accept
TIME:     40ms    BEAT: 92.75%    O(n) = 
MEMORY: 19.1MB    BEAT: 75.00%    O(n) = 
USED TIME: 04:59
LAST EDIT TIME: 2021年3月3日15:34:54
Description: 哈希表。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;

        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            dict[key].emplace_back(str);
        }
        
        vector<vector<string>> ans;
        for (auto it = dict.begin(); it != dict.end(); it ++) {
            ans.emplace_back(it->second);
        }
        
        return ans;
    }
};

// @lc code=end

