/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-30 12:33:31
 * @LastEditTime: 2021-03-30 15:11:40
 * @FilePath: \Leetcode\1807.Evaluate the Bracket Pairs of a String.cpp
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年3月30日15:11:37
Description: y总。
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

    }
};


/*
RESULT: Accept
TIME:     400ms    BEAT: 80%    O(n) = 
MEMORY: 114.5MB    BEAT: 50%    O(n) = 
LAST EDIT TIME: 2021年03月30日13:12:14
Description: 
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string, string> knowledge;
        for (int i = 0; i < k.size(); i ++) {
            knowledge[k[i][0]] = k[i][1];
        }
        string res = "";
        string tmp = "";
        int l = 0, r = 0;
        while (r < s.size()) {
            if (s[r] == '(') {
                l = r;
                while (s[r] != ')') r ++;
                tmp = s.substr(l + 1, r - l - 1);
                if (knowledge.find(tmp) == knowledge.end()) res += "?";
                else res += knowledge[tmp];
                tmp = "";
            }
            else res += s[r];
            r ++;
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<string>> k = {{"name", "bob"}, {"age", "two"}};
    string s = "(name)is(age)yearsold";
    string ans = sol.evaluate(s, k);
    cout << ans << endl; 
    system("pause");
    return 0;
}