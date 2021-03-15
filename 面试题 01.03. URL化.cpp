/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-12 22:29:47
 * @LastEditTime: 2021-03-15 22:04:02
 * @FilePath: \Leetcode\demo03.cpp
 */


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
TIME:     40ms    BEAT: 87.10%    O(n) = 
MEMORY: 21.5MB    BEAT: 84.37%    O(n) = 
LAST EDIT TIME: 2021年3月15日22:4:8
Description: 双指针。
*/

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int i = length - 1;    // i指向的是字符串最后一个字符。
        int j = S.length() - 1;    // j指向S的最后一个位置。

        for (; i >= 0; i --) {
            if (S[i] == ' ') {
                S[j --] = '0';
                S[j --] = '2';
                S[j --] = '%';
            }
            else S[j --] = S[i];
        }

        return S.substr(j + 1);
    }
};


/*
RESULT: Accept
TIME:     48ms    BEAT: 53.28%    O(n) = 
MEMORY: 25.1MB    BEAT: 41.29%    O(n) = 
USED TIME: 29:18
LAST EDIT TIME: 2021年3月12日23:2:13
Description: 理解错了题目意思。
*/

// class Solution {
// public:
//     string replaceSpaces(string S, int length) {
//         string res = "";
//         if (S.length() == 0) return "";
//         for (int i = 0; i < length; i ++) {
//             if (i > S.length() - 1) res += "%20";
//             else if (S[i] != ' ') res += S[i];
//             else res += "%20";
//         }
//         return res;
//     }
// };


int main() {
    Solution sol;
    string ans = sol.replaceSpaces("Mr John Smith    ", 13);
    cout << ans << endl;
    system("pause");
    return 0;
}

