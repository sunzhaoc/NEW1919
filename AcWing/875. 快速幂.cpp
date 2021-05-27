/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-27 15:34:57
 * @LastEditTime: 2021-05-27 16:41:24
 * @FilePath: \Leetcode\AcWing\875. 快速幂.cpp
 */
/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 */

# include<bits/stdc++.h>
using namespace std;

// 递归
long long quick_pow(int a, int k, int p) {
    if (k == 0) return 1;
    long long res = quick_pow(a, k / 2, p);
    return k % 2 == 0 ? res * res % p : res * res % p * a % p;
}

// 位运算
int quick_pow(int a, int k, int p) {
    long long res = 1, base = a;
    while (k) {
        if (k & 1) res = res * base % p;
        base = base * base % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        int a, k, p;
        scanf("%d%d%d", &a, &k, &p);
        printf("%d\n", quick_pow(a, k, p));
    }
    return 0;
}