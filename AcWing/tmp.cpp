/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-24 17:52:02
 * @LastEditTime: 2021-05-24 21:03:25
 * @FilePath: \Leetcode\AcWing\tmp.cpp
 */

# include <bits/stdc++.h>
using namespace std;


void get_prime(int x) {
    int cnt = 0;
    vector<bool> isPrime(x + 1, true);
    vector<int> primes;
    for (int i = 2; i <= x; i ++) {
        if (isPrime[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && primes[j] * i <= x; j ++) {
            isPrime[i * primes[j]] = false; 
            if (i % primes[j] == 0) break;
        }
    }
    cout << primes.size() << endl;
}


// 埃氏筛，1-n中有n/ln(n)个质数 时间复杂度约为nloglogn
void get_prime(int x) {
    int cnt = 0;
    vector<bool> st(x + 1, false);
    for (int i = 2; i <= x; i ++) {
        if (!st[i]) {
            cnt ++;
            for (int j = i; j <= x; j += i) st[j] = true;
        }
    }
    cout << cnt << endl;
}


int main() {
    int n;
    cin >> n;
    get_prime(n);
    system("pause");
    return 0;
}