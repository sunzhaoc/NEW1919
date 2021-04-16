/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-01 14:03:40
 * @LastEditTime: 2020-12-14 21:44:57
 * @FilePath: \Leetcode\941.Valid Mountain Array.cpp
 */
/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int i = 0;
        int n = arr.size();
        while (i + 1 < n - 1  && arr[i] < arr[i + 1])
        {
            i ++;
        }
        
        if (i == 0){
            return false;
        }

        while (i + 1 < n && arr[i] > arr[i + 1])
        {
            i ++;
        }
        
        if (i == n - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};


int main(){
    Solution sol1;
    vector<int> arr = {1, 2, 2, 1};
    bool A = sol1.validMountainArray(arr);
    cout << A << endl;
    system("pause");
    return 0;
}
// @lc code=end

