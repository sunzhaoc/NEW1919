/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-27 14:11:49
 * @LastEditTime: 2021-05-27 14:44:48
 * @FilePath: \Leetcode\AcWing\874. 筛法求欧拉函数.cpp
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


# include <bits/stdc++.h>
using namespace std;

int n;

long long get_euler(int n) {
    vector<bool> isPrime(n + 1);
    vector<int> prime(n), phi(n + 1);
    int cnt = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (!isPrime[i]) {
            prime[cnt ++] = i;
            phi[i] = i - 1; // 若一个数p为质数，则1到p-1均和p互质，则p的欧拉函数为p-1
        }
        for (int j = 0; prime[j] <= n / i; j ++) {
            isPrime[prime[j] * i] = true;
            if (i % prime[j] == 0) {
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            }
            phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
    
    long long res = 0;
    for (int i = 1; i <= n; i ++) res += phi[i];
    return res;
}

int main() {
    cin >> n;
    cout << get_euler(n) << endl;
    return 0;
}