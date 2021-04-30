/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-30 10:52:10
 * @LastEditTime: 2021-04-30 10:52:18
 * @FilePath: \Leetcode\AcWing\789. 数的范围.cpp
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];
    int target;
    while (cin >> target)  {
        int resL = -1, resR = -1;
        int l = 0, r = n - 1;
        
        // Find Left
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        
        if (nums[l] != target) {
            cout << resL << " " << resR << endl;
            continue;
        }
        else resL = l;
        
        // Find Right
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (r - l + 1) / 2 + l;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        resR = r;
        cout << resL << " " << resR << endl;
    }
    return 0;
}