/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-24 17:52:02
 * @LastEditTime: 2021-05-27 14:38:33
 * @FilePath: \Leetcode\AcWing\0.demo.cpp
 */

# include <bits/stdc++.h>
using namespace std;

// 线性筛。时间复杂度约为n
void get_primes(int x) {
    vector<bool> isPrime(x + 1);
    vector<int> primes(x);
    int cnt = 0;
    for (int i = 2; i <= x; i ++) {
        if (!isPrime[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= x / i; j ++) {
            isPrime[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    cout << cnt << endl;
} 


int main() {
    int n;
    cin >> n;
    get_primes(n);
    system("pause");
    return 0;
}