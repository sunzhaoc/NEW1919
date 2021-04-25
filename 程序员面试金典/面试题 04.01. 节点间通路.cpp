/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-16 15:35:35
 * @LastEditTime: 2021-03-16 16:39:18
 * @FilePath: \Leetcode\demp.cpp
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
TIME:    200ms    BEAT: 96.89%    O(n) = 
MEMORY: 50.6MB    BEAT: 97.60%    O(n) = 
LAST EDIT TIME: 2021年3月16日16:38:1
Description: 正序递归会超时。逆序就不会。
*/

class Solution {
public:
    vector<bool> visited;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        visited.resize(graph.size(), false);
        return backTrack(n, graph, start, target);
    }

    bool backTrack(int n, vector<vector<int>>& graph, int start, int target) {
        for (int i = 0; i < graph.size(); i ++) {
            if (!visited[i]) {
                if (graph[i][0] == start && graph[i][1] == target) return true;
                visited[i] = true;
                if (graph[i][1] == target && backTrack(n, graph, start, graph[i][0])) return true;    // 逆序
                // if (graph[i][0] == start && backTrack(n, graph, graph[i][1], target)) return true;   // 正序
                visited[i] = false;
            }
        }
        return false;
    }
};


/*
RESULT: Wrong！！！
Description: 并查集不能用在有向图上。
*/

// class Solution {
// public:
//     // int pre[100001];
//     int pre[13];

//     int find(int root) {
//         int son, tmp;
//         son = root;

//         while (root != pre[root]) {
//             root = pre[root];
//         }

//         while (son != root) {
//             tmp = pre[son];
//             pre[son] = root;
//             son = tmp;
//         }

//         return root;
//     }

//     bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {

//         for (int i = 0; i <= n; i ++) pre[i] = i;

//         for (auto& item: graph) {
//             pre[find(item[0])] = find(item[1]);
//         }

//         if (find(start) == find(target)) return true;
//         else return false;
//     }
// };


int main() {
    Solution sol;
    vector<vector<int>> graph = {{0, 1}, {1, 2}, {1, 3}, {1, 10}, {1, 11}, {1, 4}, {2, 4}, {2, 6}, {2, 9}, {2, 10}, {2, 4}, {2, 5}, {2, 10}, {3, 7}, {3, 7}, {4, 5}, {4, 11}, {4, 11}, {4, 10}, {5, 7}, {5, 10}, {6, 8}, {7, 11}, {8, 10}};
    bool ans = sol.findWhetherExistsPath(12, graph, 2, 3);
    cout << ans << endl; 
    system("pause");
    return 0;
}

