/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-25 14:39:39
 * @LastEditTime: 2021-05-25 14:39:39
 * @FilePath: \Leetcode\AcWing\872. 最大公约数.cpp
 */
# include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n, a, b;
    cin >> n;
    while (n --) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}