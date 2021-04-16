/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-13 13:10:56
 * @LastEditTime: 2021-01-13 14:05:01
 * @FilePath: \Leetcode\684.Redundant Connection.cpp
 */
/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
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
RESULT: Accepti
TIME:     4ms    BEAT: 99.85%    O(n) = 
MEMORY: 8.4MB    BEAT: 71.86%    O(n) = 
Description: 并查集。路径压缩真香。
*/

class Solution {
private:
    int n = 1005;
    int father[1005];

    void init() {
        for (int i = 0; i < n; i ++) {
            father[i] = i;
        }
    }

    int find(int x) {
        int son, tmp;
        son = x;
        
        while (x != father[x]){
            x = father[x];
        }

        while (son != x) {
            tmp = father[son];
            father[son] = x;
            son = tmp;
        }

        return x;
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        father[y] = x;
    }

    bool same(int x, int y) {
        x = find(x);
        y = find(y);
        return x == y;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (int i = 0; i < edges.size(); i ++) {
            if (same(edges[i][0], edges[i][1])) return edges[i];
            else join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};


/*
RESULT: Accepti
TIME:     8ms    BEAT: 95.67%    O(n) = 
MEMORY: 8.3MB    BEAT: 93.04%    O(n) = 
Description: 并查集。判断如果成环，则删除。
*/

// class Solution {
// private:
//     int n = 1005;
//     int father[1005];

//     void init() {
//         for (int i = 0; i < n; i ++) {
//             father[i] = i;
//         }
//     }

//     int find(int x) {
//         if (x == father[x]) {
//             return x;
//         }
//         return find(father[x]);
//     }

//     void join(int x, int y) {
//         x = find(x);
//         y = find(y);
//         if (x == y) return;
//         father[y] = x;
//     }

//     bool same(int x, int y) {
//         x = find(x);
//         y = find(y);
//         return x == y;
//     }

// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         init();
//         for (int i = 0; i < edges.size(); i ++) {
//             if (same(edges[i][0], edges[i][1])) return edges[i];
//             else join(edges[i][0], edges[i][1]);
//         }
//         return {};
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> ans = sol.findRedundantConnection(edges);
    cout << ans[0] << " " << ans[1] << endl;
    system("pause");
    return 0;
}


// @lc code=end

