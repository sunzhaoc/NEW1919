/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-20 11:06:37
 * @LastEditTime: 2021-05-20 11:06:37
 * @FilePath: \Leetcode\AcWing\154. 滑动窗口.cpp
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-20 09:34:06
 * @LastEditTime: 2021-05-20 10:59:32
 * @FilePath: \Leetcode\AcWing\154.cpp
 */
# include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];

    deque<int> d;
    vector<int> res;

    // 最小
    for (int l = 1 - k, r = 0; r < n; l ++, r ++) {
        if (l > 0 && nums[l - 1] == d[0]) d.pop_front();
        while (!d.empty() && d[0] > nums[r]) d.pop_front();
        while (!d.empty() && d.back() > nums[r]) d.pop_back();
        d.push_back(nums[r]);

        if (l >= 0) res.push_back(d[0]);
    }
    for (int i = 0; i < res.size(); i ++) cout << res[i] << " ";
    cout << endl;

    d.clear();
    res.clear();

    // 最大
    for (int l = 1 - k, r = 0; r < n; l ++, r ++) {
        if (l > 0 && nums[l - 1] == d[0]) d.pop_front();

        while (!d.empty() && d[0] < nums[r]) d.pop_front();
        while (!d.empty() && d.back() < nums[r]) d.pop_back();
        d.push_back(nums[r]);

        if (l >= 0) res.push_back(d[0]);
    }

    for (int i = 0; i < res.size(); i ++) cout << res[i] << " ";
    cout << endl;

    system("pause");
    return 0;
}