/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 18:31:56
 * @LastEditTime: 2021-03-18 19:46:25
 * @FilePath: \Leetcode\347.Top K Frequent Elements.cpp
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

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
TIME:     12ms    BEAT: 97.54%    O(n) = 
MEMORY: 13.3MB    BEAT: 78.85%    O(n) = 
LAST EDIT TIME: 2021年3月18日19:46:2
Description: 维护一个大小为K的自定义小根堆。。
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int num: nums) map[num] ++;

        struct cmp
        {
            bool operator() (const pair<int, int>& x, const pair<int, int>& y) {
                return x.second > y.second;
            }
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap;
    
        for (auto it = map.begin(); it != map.end(); it ++) {
            minHeap.push({it->first, it->second});
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> res;
        for (int i = 0; i < k; i ++) {
            res.emplace_back(minHeap.top().first);
            minHeap.pop();
        }
        
        return res;
    }
};


/*
RESULT: Accept
TIME:     24ms    BEAT: 43.82%    O(n) = 
MEMORY: 13.2MB    BEAT: 86.37%    O(n) = 
LAST EDIT TIME: 2021年3月18日19:37:37
Description: 自定义一个大根堆。可以进一步优化。
*/

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> map;

//         for (int num: nums) map[num] ++;

//         struct cmp
//         {
//             bool operator() (const pair<int, int>& x, const pair<int, int>& y) {
//                 return x.second < y.second;
//             }
//         };
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap;
    
//         for (auto it = map.begin(); it != map.end(); it ++) {
//             minHeap.push({it->first, it->second});
//         }

//         vector<int> res;
//         for (int i = 0; i < k; i ++) {
//             res.emplace_back(minHeap.top().first);
//             minHeap.pop();
//         }
        
//         return res;
//     }
// };


/*
RESULT: Accept
TIME:     16ms    BEAT: 86.14%    O(n) = 
MEMORY: 13.3MB    BEAT: 83.50%    O(n) = 
USED TIME: 忘了。
LAST EDIT TIME: 2021年3月18日19:21:6
Description: 哈希 + 自建的单调栈。
*/

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> map;

//         for (int num: nums) {
//             map[num] ++;
//         }

//         vector<pair<int, int>> minHeap;
//         for (auto it = map.begin(); it != map.end(); it ++) {
//             minHeap.push_back({it->first, it->second});
//         }

//         sort(minHeap.begin(), minHeap.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
//             return x.second > y.second;
//         });

//         vector<int> res;
//         for (int i = 0; i < k; i ++) {
//             res.emplace_back(minHeap[i].first);
//         }
        
//         return res;
//     }
// };


int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,2,2,2,3,3};
    vector<int> ans = sol.topKFrequent(nums, 2);
    // cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

