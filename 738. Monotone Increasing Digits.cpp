/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-11-26 17:24:07
 * @LastEditTime: 2020-12-15 13:18:52
 * @FilePath: \Leetcode\738.Monotone Increasing Digits.cpp
 */
/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;


/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.2MB    BEAT:  34.12%    O(n) = 
Description: 二刷，每日一题。
*/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        string str = to_string(N);
        int temp = 0;
        for (int i = 0; i < str.size() - 1; i ++) {
            if (str[i] < str[i + 1]) temp = i + 1;
            else if (str[i] > str[i + 1]) {
                str[temp] = str[temp] - 1;
                for (int j = temp + 1; j < str.size(); j ++) {
                    str[j] = '9';
                }
                int x = stoi(str);
                return x;
            }
        }
        return N;
    }
};


/*
RESULT: Accept
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
Description: 参考答案，贪心。
*/

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10)
            return N;
        string M = to_string(N);
        int length = M.size();
        
        int index = 0;

        for (int i = 1; i < length; i ++){
            if (M[i] > M[i - 1]){
                index = i;
            }
            if (M[i] < M[i - 1]){
                M[index]--;
                for (int j = (index+1); j < length; j ++){
                    M[j] = '9';
                }
                int ans = stoi(M);
                return ans;
            }
        }
        return N;
    }
};


int main() 
{
    Solution sol1;
    int A = sol1.monotoneIncreasingDigits(332);
    cout << A << endl;
    system("pause");
    return 0;
}
// @lc code=end

