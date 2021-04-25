/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-03 22:17:37
 * @LastEditTime: 2020-12-03 22:27:46
 * @FilePath: \Leetcode\剑指 Offer 11. 旋转数组的最小数字.cpp
 */


/*
RESULT: Accept
TIME: 4ms BEAT: 99.63%
MEMORY: 12.4MB BEAT: 5.15%
Description: 二分法
*/
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;

        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (numbers[mid] < numbers[r])  r = mid;
            else if (numbers[mid] > numbers[r]) l = mid + 1;
            else r--;
        }
        return numbers[l];
    }
};