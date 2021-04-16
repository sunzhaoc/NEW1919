/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-09 16:23:26
 * @LastEditTime: 2021-03-09 16:46:26
 * @FilePath: \Leetcode\245.Shortest Word Distance III.cpp
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
TIME:     16ms    BEAT: 52.88%    O(n) = 
MEMORY: 11.6MB    BEAT: 23.53%    O(n) = 
LAST EDIT TIME: 2021年3月9日16:45:55
Description: 代码优化了一下。
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int res = words.size();
        bool same = word1 == word2; 
        for (int i = 0; i < words.size(); i ++) {
            if (words[i] == word1) {
                if (same) {
                    p2 = p1;
                    p1 = i;
                }
                else p1 = i;
            }
            else if (words[i] == word2) {
                p2 = i;
            }
            if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
        }
        return res;
    }
};


/*
RESULT: Accept
TIME:     12ms    BEAT: 87.50%    O(n) = 
MEMORY: 11.4MB    BEAT: 58.82%    O(n) = 
USED TIME: 06:18
LAST EDIT TIME: 2021年3月9日16:41:59
Description: 分两种情况讨论就是了。
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int res = words.size();
        if (word1 != word2) {
            for (int i = 0; i < words.size(); i ++) {
                if (words[i] == word1) {
                    p1 = i;
                }
                else if (words[i] == word2) {
                    p2 = i;
                }
                if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
            }
        }
        else {
            for (int i = 0; i < words.size(); i ++) {
                if (words[i] == word1) {
                    p2 = p1;
                    p1 = i;
                }
                if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
            }
        }
        return res;
    }
};