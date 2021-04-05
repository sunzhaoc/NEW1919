/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-05 15:26:28
 * @FilePath: \Leetcode\weekcom\t1.cpp
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
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;

const int N = 1000000007;


class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> map; 

        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i - 1]) {
                map.push_back({nums[i - 1], i});
                // map[nums[i - 1]] = i;
            }
        }
        // map[nums.back()] = nums.size();
        map.push_back({nums.back(), nums.size()});

        int cnt = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] >= target) break;
            int diff = target - nums[i];
            int l = 0, r = map.size() - 1;
            bool flag = false;
            while (l < r) {
                int mid = (r - l + 1 ) / 2 + l;
                if (map[mid].first == diff) {
                    flag = true;
                    cnt += map[mid].second;
                    break;
                }
                else if (map[mid].first <= diff) l = mid;
                else r = mid - 1;
            }
            if(flag) break;
            cnt += map[r].second;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    // VI nums = {2,5,3,5};
    VI nums = {2,2,1,9};
    int target = 6;
    int ans = sol.purchasePlans(nums, target);
    cout << ans << endl;
    system("pause");
    return 0;
}
