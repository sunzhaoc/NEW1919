/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-30 12:03:27
 * @LastEditTime: 2021-01-30 12:36:03
 * @FilePath: \Leetcode\125.Valid Palindrome.cpp
 */
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
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
TIME:     4ms    BEAT: 95.24%    O(n) = 
MEMORY: 7.2MB    BEAT: 96.05%    O(n) = 
LAST EDIT TIME: 2021年1月30日12:34:55
Description: 双指针
*/

class Solution {
public:
    bool whetherChar(char s) {
        if (s >= 'a' && s <= 'z') return true;
        if (s >= 'A' && s <= 'Z') return true;
        if (s >= '0' && s <= '9') return true;
        return false;
    }
    
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 1) return true;
        int left = 0, right = len - 1;
        while (left < right) {
            if (!whetherChar(s[left]) && !whetherChar(s[right])) {
                left ++;
                right --;
            }            
            else if (!whetherChar(s[left])) left ++;
            else if (!whetherChar(s[right])) right --;
            else if (s[right] == s[left] || (s[left] >= 65 && s[left] <= 90 && s[left] + 32 == s[right]) || (s[right] >= 65 && s[right] <= 90 && s[right] + 32 == s[left])) {
                left ++;
                right --;
            }
            else return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    // bool ans = sol.isPalindrome("A man, a plan, a canal: Panama");
    bool ans = sol.isPalindrome("0P");
    cout << ans << endl;
    system("pause");
    return 0;
}
// @lc code=end

