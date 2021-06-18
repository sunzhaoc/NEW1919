/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-23 17:45:58
 * @LastEditTime: 2021-02-01 19:11:21
 * @FilePath: \Leetcode\1742.Maximum Number of Balls in a Box.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
using namespace std;


/*
RESULT: Accept
TIME:    28ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021年2月1日19:11:19
Description: 
*/

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> map;
        int sum, tmp;
        for (int i = lowLimit; i <= highLimit; i ++) {
            sum = 0;
            tmp = i;
            while (tmp != 0) {
                sum += (tmp % 10);
                tmp /= 10;
            }
            map[sum] ++;
        }
        
        auto it = map.begin();
        int ans = INT_MIN;
        while (it != map.end()) {
            ans = max(it->second, ans);
            it ++;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    int ans = sol.countBalls(5 ,15);
    cout << ans << endl; 
    system("pause");
    return 0;
}