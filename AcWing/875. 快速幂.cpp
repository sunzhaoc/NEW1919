/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-27 15:34:57
 * @LastEditTime: 2021-05-27 16:25:47
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