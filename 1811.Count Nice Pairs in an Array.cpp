/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-03 22:22:00
 * @LastEditTime: 2021-04-03 23:59:51
 * @FilePath: \Leetcode\dmeo01 copy 3.cpp
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

typedef vector<int> VI;
typedef vector<int> VII;
typedef long long LL;
const int N = 1000000007;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<LL, int> map;
        for (int num: nums) map[rev(num)] ++;
        LL res = 0;
        for (auto it = map.begin(); it != map.end(); it ++) res = (res + ((it->second % N) * (it->second - 1) % N) / 2) % N;
        return res;
    }

    LL rev(LL x) {       
        string s_x = to_string(x);
        reverse(s_x.begin(), s_x.end());
        LL a = stoi(s_x);
        return x - a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,11,1,97};
    int ans = sol.countNicePairs(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
