# include <bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 10;
int nums[N][N], diff[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    diff[x1][y1] += c;
    diff[x2 + 1][y1] -= c;
    diff[x1][y2 + 1] -= c;
    diff[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) cin >> nums[i][j];
    //下面两个都行
    // for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) insert(i, j, i, j, nums[i][j]); // 官解。
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) diff[i][j] = nums[i][j] - nums[i - 1][j] - nums[i][j - 1] + nums[i - 1][j - 1]; // 自己写的，好理解。

    
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
