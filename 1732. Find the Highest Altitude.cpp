/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-23 17:45:53
 * @LastEditTime: 2021-01-23 22:33:18
 * @FilePath: \Leetcode\demo1.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int tmp = 0;
        int maxLen = 0;
        for (int i = 0; i < gain.size(); i ++) {
            tmp += gain[i];
            maxLen = max(maxLen, tmp);
        }
        return maxLen;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-5,1,5,0,-7};
    int ans = sol.largestAltitude(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
