/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-30 11:10:06
 * @LastEditTime: 2021-04-30 11:13:22
 * @FilePath: \Leetcode\AcWing\790. 数的三次方根.cpp
 */
# include <bits/stdc++.h>
using namespace std;

double x;
int main() {
    cin >> x;
    double l = -10000, r = 10000;
    while (r - l > 1e-9) {
        double mid = (r - l) / 2 + l;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%.6f", l);
    return 0;
}