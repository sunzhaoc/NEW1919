/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-24 14:22:36
 * @LastEditTime: 2020-12-24 14:51:39
 * @FilePath: \Leetcode\剑指 Offer 38. 字符串的排列.cpp
 */
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:   132ms    BEAT: 52.74%    O(n) = 
MEMORY:  37MB    BEAT: 12.01%    O(n) = 
Description: 
*/

class Solution {
public:
    vector<string> ans;
    string s_copy;

    vector<string> permutation(string s) {
        s_copy = s;
        dfs(0);
        return ans;
    }

private:
    void dfs(int x) {
        if (x == s_copy.size() - 1) {
            ans.push_back(s_copy);
            return;
        }

        unordered_set<char> dic;
        for (int i = x; i < s_copy.size(); i ++) {
            if (dic.count(s_copy[i])) continue;
            dic.insert(s_copy[i]);
            swap(s_copy[i], s_copy[x]);
            dfs(x + 1);
            swap(s_copy[i], s_copy[x]);
        }
    }
};


int main() {
    Solution sol;
    vector<string> ans = sol.permutation("abc");
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}