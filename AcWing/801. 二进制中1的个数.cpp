/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-25 21:59:52
 * @LastEditTime: 2021-04-30 11:04:56
 * @FilePath: \Leetcode\AcWing\00_test.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];
    for (int i = 0; i < n; i ++) {
        int cnt = 0;
        while (nums[i]) {
            nums[i] = nums[i] & (nums[i] - 1);
            cnt ++;
        }
        nums[i] = cnt;
    }
    
    for (int i = 0; i < n; i ++) cout << nums[i] << " ";
    system("pause");
    return 0;
}