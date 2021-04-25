/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-18 09:08:55
 * @LastEditTime: 2021-01-18 10:32:13
 * @FilePath: \Leetcode\721.Accounts Merge.cpp
 */
/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;


/*
RESULT: Accept
TIME:    108ms    BEAT: 99.61%    O(n) = 
MEMORY: 30.1MB    BEAT: 68.80%    O(n) = 
LAST EDIT TIME: 2021年1月18日10:32:4
Description: 并查集。
*/

class Solution {
private:
    int parent[1001];

    int find(int x) {
        int son, tmp;
        son = x;

        while (parent[x] != x) {
            x = parent[x];
        }

        while (son != x) {
            tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }

        return x;
    }

public: 
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }

        unordered_map<string, int> father;
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < accounts[i].size(); j ++) {
                // map 中存在
                if (father.count(accounts[i][j])) {
                    int root = father[accounts[i][j]];
                    parent[find(root)] = parent[i];
                }
                // map中不存在
                else {
                    father[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, unordered_set<string>> dump;
        for (int i = 0; i < n; i ++) {
            int root = find(i);
            for (int j = 1; j < accounts[i].size(); j ++) {
                dump[root].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for (auto node: dump) {
            vector<string> res;
            int root = node.first;
            string name = accounts[root][0];
            res.push_back(name);
            for (auto item: node.second) {
                res.push_back(item);
            }
            sort(res.begin(), res.end());
            ans.push_back(res);
        }
        return ans;

    }
};


int main() {
    Solution sol;
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    vector<vector<string>> ans = sol.accountsMerge(accounts);
    for (int i = 0; i < ans.size(); i ++) {
        for (int j = 0; j < ans[i].size(); j ++) {
            cout << ans[i][j] << endl;
        }
    }
    system("pause");
    return 0;
}

// @lc code=end

