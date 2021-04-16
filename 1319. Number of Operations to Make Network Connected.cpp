/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-23 12:46:30
 * @LastEditTime: 2021-01-23 13:05:37
 * @FilePath: \Leetcode\1319.Number of Operations to Make Network Connected.cpp
 */
/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 13:57
LAST EDIT TIME: 2021年1月23日13:2:47
Description: 
*/

class Solution {
public:
    vector<int> parent;
    int count, rest;

    void init(int n) {
        for (int i = 0; i < n; i ++) {
            parent.push_back(i);
        }
        count = n;
        rest = 0;
    }

    int find(int x) {
        int son, tmp;
        son = x;

        while (x != parent[x]) {
            x = parent[x];
        }

        while (parent[son] != x) {
            tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }
        return x;
    }

    void merge(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
            count --;
        }
        else rest ++;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int numRow = connections.size();
        int numCol = connections[0].size();

        init(n);

        for (auto& it: connections) {
            merge(it[0], it[1]);
        }

        if (rest < count - 1) return -1;
        else return count - 1;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    int ans = sol.makeConnected(4, connections);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

