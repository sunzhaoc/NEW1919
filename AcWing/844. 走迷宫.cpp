/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-26 09:16:47
 * @LastEditTime: 2021-05-26 09:33:01
 * @FilePath: \Leetcode\AcWing\844. 走迷宫.cpp
 */
# include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m));
    for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) cin >> s[i][j];
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    deque<pair<int, int>> q;
    q.push_back(make_pair(0, 0));
    s[0][0] = 1;
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int i = 0; i < 4; i ++) {
            int tmpX = x + dx[i], tmpY = y + dy[i];
            if (tmpX == n - 1 && tmpY == m - 1) {
                cout << s[x][y] << endl;
                return 0;
            }
            if (tmpX >= 0 && tmpX < n && tmpY >= 0 && tmpY < m && s[tmpX][tmpY] == 0) {
                s[tmpX][tmpY] = s[x][y] + 1;
                q.push_back(make_pair(tmpX, tmpY));
            }
        }
    }
    return 0;
}