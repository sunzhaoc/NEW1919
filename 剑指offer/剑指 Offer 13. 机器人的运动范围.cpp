/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2020-12-30 14:28:24
 * @LastEditTime: 2020-12-30 15:44:07
 * @FilePath: \Leetcode\剑指 Offer 13. 机器人的运动范围.cpp
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 74.75%    O(n) = mn
MEMORY: 7.1MB    BEAT: 41.49%    O(n) = mn
Description: 递推。
*/

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        int ans = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
                if (i - 1 >= 0) visited[i][j] |= visited[i - 1][j];
                if (j - 1 >= 0) visited[i][j] |= visited[i][j - 1];
                ans += visited[i][j];
            }
        }
        return ans;
    }

private:
    int get(int x) {
        if (x < 10) return x;
        else return (x % 10) + (x / 10);
    }
};


/*
RESULT: Accept
TIME:    36ms    BEAT: 5.93%    O(n) = mn
MEMORY: 9.9MB    BEAT: 5.01%    O(n) = mn
Description: BFS
*/

// class Solution {
// public:
//     int movingCount(int m, int n, int k) {
//         int ans = 0;
//         vector<vector<bool>> visited(m, vector<bool>(n, 0));
//         queue<vector<int>> que;
//         que.push({0, 0, 0, 0});
//         while (que.size() > 0) {
//             vector<int> x = que.front();
//             que.pop();
//             // 横坐标，纵坐标，横坐标各位和，纵坐标各位和
//             int i = x[0], j = x[1], si = x[2], sj = x[3];
//             if (i >= m || j >= n || si + sj > k || visited[i][j]) continue;
//             visited[i][j] = true;
//             ans ++;
//             // 向下移动
//             que.push({i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj});
//             // 向右移动
//             que.push({i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8});
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    // int ans = sol.movingCount(2, 3, 1);
    // int ans = sol.movingCount(3, 1, 0);
    int ans = sol.movingCount(16, 8, 4);
    cout << ans << endl;
    system("pause");
    return 0;
}