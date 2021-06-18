/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-20 23:30:39
 * @LastEditTime: 2021-03-23 16:37:43
 * @FilePath: \Leetcode\1799.Maximize Score After N Operations.cpp
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


/*
RESULT: Accept
TIME:   376ms    BEAT: 32.39%    O(n) = 
MEMORY: 7.9MB    BEAT: 68.04%    O(n) = 
LAST EDIT TIME: 2021年3月23日16:10:38
Description: Y总。状态压缩DP。
*/

class Solution {
public:
    int gcd (int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(1 << n);
        for (int i = 0; i < 1 << n; i ++) {
            int cnt = 0;
            // 统计 i 里 0 的个数。
            for (int j = 0; j < n; j ++) {
                if (!(i >> j & 1))  cnt ++;
            }
            cnt = cnt / 2 + 1;
            
            // 枚举所有的 1
            for (int j = 0; j < n; j ++) {
                if (i >> j & 1) {
                    // 更新第二个 1
                    for (int k = j + 1; k < n; k ++) {
                        if (i >> k & 1) {
                            f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + gcd(nums[j], nums[k]) * cnt);
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};


/*
RESULT: Wrong
Description: 比赛的时候写的。
*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        pair<int, int> maxPair;
        int maxGcd = INT_MIN;
        int score = 0;
        sort(nums.begin(), nums.end());
        for (int k = nums.size() / 2; k > 0; k --) {
            maxGcd = INT_MIN;
            for (int i = 0; i < nums.size(); i ++) {
                for (int j = i + 1; j < nums.size(); j ++) {
                    if (measure(nums[i], nums[j]) > maxGcd) {
                        maxPair = {nums[i] ,nums[j]};
                        maxGcd = measure(nums[i], nums[j]);
                    }
                    if (measure(nums[i], nums[j]) == maxGcd) {
                        int x = 0;
                    }
                }
            }
            
                score += maxGcd * k;
                nums.erase(remove(nums.begin(), nums.end(), maxPair.first),nums.end());
                nums.erase(remove(nums.begin(), nums.end(), maxPair.second),nums.end());
        }
        return score;
    }

    int measure(int x, int y){	
        int z = y;
        while (x % y != 0) {
            z = x % y;
            x = y;
            y = z;	
        }
        return z;
    }

};



int main() {
    Solution sol;
    // vector<int> nums = {3,4,6,8};
    // vector<int> nums = {1,2,3,4,5,6};
    vector<int> nums = {109497,983516,698308,409009,310455,528595,524079,18036,341150,641864,913962,421869,943382,295019};
    int ans = sol.maxScore(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}
