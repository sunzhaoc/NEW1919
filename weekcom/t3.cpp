/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-04 10:06:53
 * @LastEditTime: 2021-04-04 11:00:59
 * @FilePath: \Leetcode\weekcom\t3.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
const int N = 1000000007;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        LL res = 0;

        vector<int> diff;
        for (int i = 0; i < n; i ++) diff.push_back(abs(nums1[i] - nums2[i]));

        int maxNum = INT_MIN;
        int maxid = -1;
        for (int i = 0; i < n; i ++) {
            if (diff[i] > maxNum) {
                maxNum = diff[i];
                maxid = i;
            }
        }

        int num2 = nums2[maxid];
        int ans = INT_MAX;
        for (int i = 0; i < n; i ++) {
            int test = abs(nums1[i] - num2);
            if (abs(nums1[i] - num2) < ans) {
                ans = abs(nums1[i] - num2);
            }
        }

        diff[maxid] = ans;

        for (int i = 0; i < n; i ++) {
            res += diff[i];
            res %= N;
        }
        return res;
        
    }
};



int main() {
    Solution sol;
    vector<int> nums1 = {1,10,4,4,2,7};
    vector<int> nums2 = {9,3,5,1,7,4};
    int ans = sol.minAbsoluteSumDiff(nums1, nums2);
    cout << ans << endl; 
    system("pause");
    return 0;
}
