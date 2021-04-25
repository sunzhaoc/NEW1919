/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-04 10:05:59
 * @LastEditTime: 2021-04-04 14:48:07
 * @FilePath: \Leetcode\1813.Truncate Sentence.cpp
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

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

/*
RESULT: Accept
Description: 比赛写的。
*/

class Solution {
public:
    string truncateSentence(string st2, int k) {
        string ans = "";
        int l = 0;
        int r = 0;
        int cnt = 0;
        while(r < st2.size()) {
            if (r == st2.length() - 1 ||st2[r + 1] == ' ') {
                ans += st2.substr(l, r - l + 1);
                r += 2;
                l = r;
                cnt ++;           
                 if (cnt == k) break;
            else ans += " ";
            }
            else r ++;

        }
        return ans;
    }
};