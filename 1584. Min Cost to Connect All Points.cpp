/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-19 10:12:26
 * @LastEditTime: 2021-01-19 16:03:00
 * @FilePath: \Leetcode\1584.Min Cost to Connect All Points.cpp
 */
/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
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
TIME:    132ms    BEAT: 90.42%    O(n) = 
MEMORY: 26.1MB    BEAT: 72.67%    O(n) = 
LAST EDIT TIME: 
Description: 最小生成树 - Prim方法。
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        int start = 0;

        vector<vector<int>> G(n, vector<int>(n));
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                G[i][j] = dist;
                G[j][i] = dist;
            }
        }

        vector<int> lowcost(n, INT_MAX);
        vector<int> v(n, -1);

        v[start] = 0;
        for (int i = 0; i < n; i ++) {
            if (i == start) continue;
            lowcost[i] = G[i][start];
        }

        for (int i = 1; i < n; i ++) {
            int minIdx = -1;
            int minVal = INT_MAX;

            for (int j = 0; j < n; j ++) {
                if (v[j] == 0) continue;
                if (lowcost[j] < minVal) {
                    minIdx = j;
                    minVal = lowcost[j];
                }
            }

            res += minVal;
            v[minIdx] = 0;
            lowcost[minIdx] = -1;

            for (int j = 0; j < n; j ++) {
                // 这步判断是整个程序的核心。
                if (v[j] == -1 && G[j][minIdx] < lowcost[j]) {
                    lowcost[j] = G[j][minIdx];
                }
            }
        }
        
        return res;
    }
};


/*
RESULT: Accept
TIME:    564ms    BEAT: 63.79%    O(n) = nlogn + mam
MEMORY: 56.9MB    BEAT: 54.68%    O(n) = n
LAST EDIT TIME: 2021年1月19日14:11:59
Description: 并查集。最小生成树 - Kruskal算法。
*/

// struct VP {
//     int start, end, len;
// };


// class Solution {
// public:
//     vector<int> parent;    
//     vector<int> size; // 表示以该点为根结点的结点数量。
//     vector<int> len;
//     int num;

//     int find(int x) {
//         int son, tmp;
//         son = x;
//         while (x != parent[x]) {
//             x = parent[x];
//         }

//         while (son != x) {
//             tmp = parent[son];
//             parent[son] = x;
//             son = tmp;
//         }

//         return x;
//     }

//     int merge(int x, int y, int length) {
//         int rootX = find(x);
//         int rootY = find(y);
//         if (rootX != rootY) {
//             parent[rootY] = rootX;
//             size[rootX] += size[rootY];
//             len[rootX] += len[rootY] + length;
//             if (size[rootX] == num) return len[rootX];
//         }
//         return -1;
//     }

//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int res = 0;
//         int n = points.size();
//         num = n;

//         parent.resize(points.size());
//         size.resize(points.size(), 1);
//         len.resize(points.size(), 0);
//         for (int i = 0; i < n; i ++) {
//             parent[i] = i;
//         }

//         vector<VP> edges;

//         for (int i = 0; i < n; i ++) {
//             for (int j = i + 1; j < n; j ++) {
//                 VP vp = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
//                 edges.emplace_back(vp);
//             }
//         }

//         // 该排序知道思路，但这里用了sort函数，不过不是重点。
//         sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
//             return a.len < b.len;
//         });

//         for (auto& e: edges) {
//             res = merge(e.start, e.end, e.len);
//             if (res != -1) return res;
//         }
//         return 0;
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> point = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    // vector<vector<int>> point = {{3,12},{-2,5},{-4,1}};
    // vector<vector<int>> point = {{0,0},{1,1},{1,0},{-1,1}};
    // vector<vector<int>> point = {{-1000000,-1000000},{1000000,1000000}};
    // vector<vector<int>> point = {{0,0}};
    int ans = sol.minCostConnectPoints(point);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

