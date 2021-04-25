/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-17 10:13:36
 * @LastEditTime: 2021-01-18 11:20:17
 * @FilePath: \Leetcode\1725.Number Of Rectangles That Can Form The Largest Square.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     40ms    BEAT: 100.00%    O(n) = 
MEMORY: 18.1MB    BEAT: 100.00%    O(n) = 
USED TIME: 11：00
LAST EDIT TIME: 2021年1月18日11:18:56
Description: 比赛的时候写的。
*/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> map;

        int max_num = 0;
        
        for (int i = 0; i < rectangles.size(); i ++) {
            int tmp = min(rectangles[i][0], rectangles[i][1]);
            map[tmp] ++;
            if (tmp > max_num) {
                max_num = tmp;
            }
        }

        return map[max_num];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> nums = {{5,8},{3,9},{5,12},{16,5}};
    int ans = sol.countGoodRectangles(nums);
    cout << ans << endl;
    system("pause");
    return 0;
}