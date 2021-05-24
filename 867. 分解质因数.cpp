/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-24 16:22:18
 * @LastEditTime: 2021-05-24 16:22:19
 * @FilePath: \Leetcode\867. 分解质因数.cpp
 */
# include<bits/stdc++.h>
using namespace std;

void divede(int x) {
    for (int i = 2; i <= x / i; i ++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
                x /= i;
                s ++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (x > 1) printf("%d %d\n", x, 1);
    puts("");
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) {
        divede(a[i]);
    }
    return 0;
}