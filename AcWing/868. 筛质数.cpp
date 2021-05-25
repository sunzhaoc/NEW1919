/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-24 17:52:02
 * @LastEditTime: 2021-05-24 22:22:01
 * @FilePath: \Leetcode\AcWing\tmp.cpp
 */

# include <bits/stdc++.h>
using namespace std;

// 线性筛。时间复杂度约为n
void get_primes(int x) {
    vector<bool> isPrime(x + 1);
    vector<int> primes;
    for (int i = 2; i <= x; i ++) {
        if (!isPrime[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && primes[j] * i <= x; j ++) {
            isPrime[i * primes[j]] = true; 
            if (i % primes[j] == 0) break;
        }
    }
    cout << primes.size() << endl;
}


// 埃氏筛，1-n中有n/ln(n)个质数 时间复杂度约为nloglogn
void get_primes(int x) {
    int cnt = 0;
    vector<bool> isPrime(x + 1);
    for (int i = 2; i <= x; i ++) {
        if (!isPrime[i]) {
            cnt ++;
            for (int j = i + i; j <= x; j += i) isPrime[j] = true;
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