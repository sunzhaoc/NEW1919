/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-30 12:33:01
 * @LastEditTime: 2021-03-30 15:00:53
 * @FilePath: \Leetcode\1805.Number of Different Integers in a String.cpp
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT:  96.66%    O(n) = 
LAST EDIT TIME: 2021年3月30日15:0:34
Description: Y总。
*/

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> num;
        for (int i = 0; i < word.size(); i ++) {
            if (!isdigit(word[i])) continue;
            string s;
            int j = i;
            while (j < word.size() && isdigit(word[j])) s += word[j ++];
            int k = 0;
            while (k + 1 < s.size() && s[k] == '0' ) k ++;
            num.insert(s.substr(k));
            i = j;
        }
        return num.size();
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 56%    O(n) = 
MEMORY: 6.3MB    BEAT: 76%    O(n) = 
LAST EDIT TIME: 2021年03月20日12:46:14
Description: 
*/

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        int r = 0;
        string num = "@";
        while (r < word.size()) {
            if (word[r] >= '0' && word[r] <= '9') {
                if (num == "@") num = "";
                num += word[r];
                r ++;
            }
            else {
                if (num != "@") {
                    num = clearZero(num);
                    st.insert(num);
                }
                num = "@";
                r ++;
            }
        }
        if (num != "@") {
            num = clearZero(num);
            st.insert(num);
        }
        return st.size();
    }

    string clearZero(string s) {
        int l = 0;
        while (s[l] == '0') {
            l ++;
        }
        return s.substr(l, s.length() - l);
    }
};


int main() {
    Solution sol;
    // int ans = sol.numDifferentIntegers("leet1234code234");
    // int ans = sol.numDifferentIntegers("a123bc34d8ef34");
    int ans = sol.numDifferentIntegers("a1b01c001");
    cout << ans << endl;
    system("pause");
    return 0;
}
