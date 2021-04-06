/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2020-12-24 18:40:37
 * @LastEditTime: 2020-12-24 19:40:52
 * @FilePath: \Leetcode\剑指 Offer 40. 最小的k个数.cpp
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:    116ms    BEAT: 32.11%    O(n) = nlogk
MEMORY: 19.4MB    BEAT: 28.42%    O(n) = k
Description: 堆。优先队列。
*/

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if (k == 0) return ans;

        priority_queue<int> Q;
        
        for (int i = 0; i < k; i ++) {
            Q.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i ++) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        
        for (int i = 0; i < k; i ++) {
            ans[i] = Q.top();
            Q.pop();
        }

        return ans;
    }
};


/*
RESULT: Accept
TIME:   72ms    BEAT: 70.31%    O(n) = nlogn
MEMORY: 19MB    BEAT: 51.31%    O(n) = logn
Description: 排序法。时间复杂度即为排序的复杂度。
*/

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> ans;
//         sort(arr.begin(), arr.end());
//         for (int i = 0; i < k; i ++) {
//             ans.push_back(arr[i]);
//         }
//         return ans;
//     }
// };


int main() {
    Solution sol;
    vector<int> arr = {3, 2, 1};
    vector<int> ans = sol.getLeastNumbers(arr, 2);
    for (int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;
    system("pause");
    return 0;
}