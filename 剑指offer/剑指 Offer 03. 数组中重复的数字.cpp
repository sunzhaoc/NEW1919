/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-03 21:04:26
 * @LastEditTime: 2020-12-03 21:50:02
 * @FilePath: \Leetcode\剑指 Offer 03. 数组中重复的数字.cpp
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME: 108ms BEAT: 51.19%
MEMORY: 28.3MB BEAT: 5.01%
Description: 
*/
class Solution {
public:
    int findRepeatNumber(vector<int> nums) {
        unordered_map <int, int> list; 
        for (int i = 0; i < nums.size(); i++){
            if(++list[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
};


int main(){
    Solution sol;
    int A = sol.findRepeatNumber({2, 3, 1, 0, 2, 5, 3});
    cout << A << endl;
    system("pause");
    return 0;
}