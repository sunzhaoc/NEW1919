/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-15 09:45:28
 * @LastEditTime: 2021-01-15 12:28:24
 * @FilePath: \Leetcode\947.Most Stones Removed with Same Row or Column.cpp
 */
/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
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
TIME:    236ms    BEAT: 41.21%    O(n) = na(n)
MEMORY: 13.8MB    BEAT: 71.21%    O(n) = n
LAST EDIT TIME: 2021年1月15日11:20:35
Description: 优化了一下空间。
*/

class Solution {
public:
    vector<int> parent;
    int count = 0;

    void init(int n) {
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        int son, tmp;
        son = x;

        while (x != parent[x]) {
            x = parent[x];
        }

        while (son != x) {
            tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }
        return x;
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // 连通两个部分。
        if (rootX != rootY) {
            parent[rootY] = rootX;
            count ++; 
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        init(n);
        
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    merge(i, j);
                }
            }
        }
        return count;
    }
};


/*
RESULT: Accept
TIME:    320ms    BEAT: 28.14%    O(n) = na(n)
MEMORY: 14.1MB    BEAT: 66.66%    O(n) = n
LAST EDIT TIME: 2021年1月15日11:5:43
Description:又tm是并查集。
https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/solution/tu-jie-bing-cha-ji-by-yexiso-nbcz/
*/

// class Solution {
// public:
//     vector<int> parent;
//     vector<int> rank;
//     int count = 0;

//     void init(int n) {
//         vector<int> tmp(n);
//         rank = tmp;
//         for (int i = 0; i < n; i ++) {
//             tmp[i] = i;
//         }
//         parent = tmp;
//     }

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

//     void merge(int x, int y) {
//         int rootX = find(x);
//         int rootY = find(y);

//         // 连通两个部分。
//         if (rootX != rootY) {
//             if (rank[rootX] < rank[rootY]) {
//                 swap(rootX, rootY);
//             }
//             parent[rootY] = rootX;
//             if (rank[rootX] == rank[rootY]) rank[rootX] += 1;
//             count ++; 
//         }
//     }


//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
        
//         init(n);
        
//         for (int i = 0; i < n; i ++) {
//             for (int j = i + 1; j < n; j ++) {
//                 // cout << stones[i][0] << " " << stones[j][0] << endl;
//                 // cout << stones[i][1] << " " << stones[j][1] << endl;
//                 if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
//                     merge(i, j);
//                 }
//             }
//         }
//         return count;
//     }
// };

int main() {
    Solution sol;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    // vector<vector<int>> stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    int ans = sol.removeStones(stones);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

