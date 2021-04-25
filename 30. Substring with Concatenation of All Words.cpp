/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-18 21:01:37
 * @LastEditTime: 2021-03-23 11:17:02
 * @FilePath: \Leetcode\30.Substring with Concatenation of All Words.cpp
 */
/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
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
TIME:     32ms    BEAT: 91.47%    O(n) = 
MEMORY: 15.9MB    BEAT: 87.21%    O(n) = 
USED TIME: 09:48
LAST EDIT TIME: 2021年3月23日11:9:10
Description: 好无聊的题。。。
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.length();

        if (n == 0 || words.empty()) return res;

        unordered_map<string, int> map;
        for (string& word: words) {
            map[word] ++;
        }
        
        int wordSize = words[0].size();
        int wordNum = words.size();

        for (int i = 0; i < wordSize; i ++) {
            int left = i;
            int right = i;
            int cnt = 0;

            unordered_map<string, int> curMap;

            while (right + wordSize <= n) {
                string curWord = s.substr(right, wordSize);
                right += wordSize;

                if (map.find(curWord) != map.end()) {
                    curMap[curWord] ++;
                    cnt ++;
                    while (curMap[curWord] > map[curWord]) {
                        string ts = s.substr(left, wordSize);
                        left += wordSize;
                        cnt --;
                        curMap[ts] --;
                    }
                    if (cnt == wordNum) res.push_back(left);
                }
                else {
                    left = right;
                    cnt = 0;
                    curMap.clear();
                }
            }
        }
        return res;
    }
};

// @lc code=end

