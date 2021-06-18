/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-18 21:00:44
 * @LastEditTime: 2021-03-19 16:25:17
 * @FilePath: \Leetcode\166.Fraction to Recurring Decimal.cpp
 */
/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.1MB    BEAT:  84.42%    O(n) = 
USED TIME: 30:12
LAST EDIT TIME: 2021年3月19日16:24:35
Description: 小数部分的处理要看看。
*/

class Solution {
public:
    string fractionToDecimal(int num, int de) {
        if (num == 0) return "0";

        string res = "";
        if ((num < 0 && de > 0) || (num > 0 && de < 0)) res += "-";

        long long numerator = abs(num * 1ll);
        long long denominator = abs(de * 1ll);

        res += to_string(numerator / denominator);

        numerator %= denominator;
        if (numerator == 0) return res;
        res += ".";
        int id = res.size() - 1;
        unordered_map<int, int> map;
        while (numerator && map.count(numerator) == 0) {
            map[numerator] = ++ id;
            numerator *= 10;
            res += to_string(numerator / denominator);
            numerator %= denominator;
        }   
        if (map.count(numerator) != 0) {
            res.insert(map[numerator], "(");
            res += ")";
        }
        return res;
    }
};


int main() {
    Solution sol;
    string ans = sol.fractionToDecimal(4, 333);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

