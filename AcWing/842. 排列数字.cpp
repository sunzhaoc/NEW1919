/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-25 15:26:41
 * @LastEditTime: 2021-05-25 15:26:41
 * @FilePath: \Leetcode\AcWing\842. 排列数字.cpp
 */
# include<bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int>& used, vector<int>& nums) {
    if (used.size() == n) {
        for (int& x: used) cout << x << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < nums.size(); i ++) {
        if (nums[i] == -1) continue;
        used.push_back(nums[i]);
        nums[i] = -1;
        dfs(n, used, nums);
        nums[i] = i + 1;
        used.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums, used;
    for (int i = 1; i <= n; i ++) nums.push_back(i);
    dfs(n, used, nums);
    return 0;
}