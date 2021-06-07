/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-06-02 09:39:30
 * @LastEditTime: 2021-06-02 09:39:30
 * @FilePath: \Leetcode\AcWing\799. 最长连续不重复子序列.cpp
 */
# include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];
    int res = 1, l = 0, r = 0;
    unordered_map<int, int> m;
    while (r < n) {
        if (m.find(nums[r]) != m.end() && m[nums[r]] > 0) {
            while (nums[l] != nums[r]) {
                m[nums[l]] --;
                l ++;
            }
            l ++;

            r ++;
            continue;
        }
        m[nums[r]] ++;
        res = max(res, r - l + 1);
        r ++;
    }
    cout << res << endl;
    return 0;
}