/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-20 23:30:39
 * @LastEditTime: 2021-03-20 23:58:55
 * @FilePath: \Leetcode\demp4.cpp
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
