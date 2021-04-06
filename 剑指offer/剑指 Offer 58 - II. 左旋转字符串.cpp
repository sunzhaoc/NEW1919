/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-04 16:36:33
 * @LastEditTime: 2020-12-04 20:54:52
 * @FilePath: \Leetcode\剑指 Offer 58 - II. 左旋转字符串.cpp
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


/*
RESULT: Accept
TIME:     4ms    BEAT: 89.91%    O(n) = 1?
MEMORY: 7.2MB    BEAT: 84.35%    O(n) = 1?
Description: 不能申请额外空间，只能在本串上操作。使用algorithm下的reverse函数进行操作。
*/

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
};


/*
RESULT: Accept
TIME:     4ms    BEAT: 89.91%    O(n) = 1?
MEMORY: 8.1MB    BEAT:  9.79%    O(n) = 1?
Description: 不能申请额外空间，只能在本串上操作。使用substr函数对字符串进行切片操作。
*/

// class Solution {
// public:
//     string reverseLeftWords(string s, int n) {
//         return (s + s).substr(n, s.size());
//     }
// };


int main(){
    Solution sol;
    string ans = sol.reverseLeftWords("abcdefg", 2);
    cout << ans << endl;
    system("pause");
    return 0;
}