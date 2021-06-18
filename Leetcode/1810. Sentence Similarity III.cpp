/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-04 00:03:07
 * @LastEditTime: 2021-04-04 14:42:37
 * @FilePath: \Leetcode\1810.Sentence Similarity III.cpp
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

typedef vector<int> VI;
typedef vector<int> VII;


/*
RESULT: Accept
Description: 比赛写的。
*/

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() > s2.length()) {
            string tmp = s2;
            s2 = s1;
            s1 = tmp;
        }

        deque<string> st1;
        int l = 0, r = 0;
        while(r < s1.size()) {
            if (r == s1.length() - 1 ||s1[r + 1] == ' ') {
                st1.push_back(s1.substr(l, r - l + 1));
                r += 2;
                l = r;
            }
            else r ++;
        }

        deque<string> st2;
        l = 0;
        r = 0;
        while(r < s2.size()) {
            if (r == s2.length() - 1 || s2[r + 1] == ' ') {
                st2.push_back(s2.substr(l, r - l + 1));
                r += 2;
                l = r;
            }
            else r ++;
        }

        while(st1.size()) {
            if (st1.front() != st2.front() && st1.back() != st2.back()) return false;
            if (st1.front() == st2.front()) {
                st1.pop_front();
                st2.pop_front();
            }
            else {
                st1.pop_back();
                st2.pop_back();
            }
        }

        return true;
    }
};