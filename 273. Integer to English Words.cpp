/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-18 20:59:51
 * @LastEditTime: 2021-03-19 14:31:56
 * @FilePath: \Leetcode\273.Integer to English Words.cpp
 */
/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
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
TIME:     4ms    BEAT: 79.00%    O(n) = 
MEMORY: 6.2MB    BEAT: 82.94%    O(n) = 
USED TIME: 01:12:16
LAST EDIT TIME: 2021年3月19日14:31:22
Description: 有点麻烦。倒是不难。
*/

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int billion = num / 1000000000;
        int million = (num - billion * 1000000000) / 1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int rest = num - billion * 1000000000 - million * 1000000 - thousand * 1000;
        
        string res = "";

        if (billion != 0) {
            res = three(billion) + " Billion";
        }
        if (million != 0) {
            if (res != "") res += " ";
            res += three(million) + " Million";
        }
        if (thousand != 0) {
            if (res != "") res += " ";
            res += three(thousand) + " Thousand";
        }
        if (rest != 0) {
            if (res != "") res += " ";
            res += three(rest);
        }

        return res;
    }

    string three(int num) {
        int hundred = num / 100;
        int rest = num - hundred * 100;
        string res = "";
        if (hundred * rest != 0) res = one(hundred) + " Hundred " + two(rest);
        else if (hundred == 0 && rest != 0) res = two(rest);
        else if (hundred != 0 && rest == 0) res = one(hundred) + " Hundred";
        return res;
    }

    string two(int num) {
        if (num == 0) return "";
        else if (num < 10) return one(num);
        else if (num < 20) return twoLessThan20(num);
        else {
            int tenner = num / 10;
            int rest = num - tenner * 10;
            if (rest != 0) return ten(tenner) + " " + one(rest);
            else return ten(tenner);
        }
    }

    string one(int num) {
        switch (num)
        {
            case 1: return "One";            
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";            
        }
        return "";
    }

    string twoLessThan20(int num) {
        switch (num)
        {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return "";
    }

    string ten(int num) {
        switch (num)
        {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        return "";
    }
};


int main() {
    Solution sol;
    // string ans = sol.numberToWords(1234567891);
    string ans = sol.numberToWords(123);
    cout << ans << endl; 
    system("pause");
    return 0;
}

// @lc code=end

