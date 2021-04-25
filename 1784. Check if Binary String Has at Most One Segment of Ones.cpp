/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-07 10:18:55
 * @LastEditTime: 2021-03-07 22:36:24
 * @FilePath: \Leetcode\5697.Check if Binary String Has at Most One Segment of Ones.cpp
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
TIME:     0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6.1MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021年3月7日22:35:39
Description: Y总。
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j && s[i] == '0') i ++;
        while (i <= j && s[j] == '0') j --;
        for (int k = i; k <= j; k ++) {
            if (s[k] == '0') return false;
        }
        return true;
    }
};


/*
RESULT: Accept
TIME:   4ms    BEAT: 100.00%    O(n) = 
MEMORY: 6MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 
Description: 比赛写的。
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        if (s.length()==0) return false;
        if (s.length() == 1 && s[0] == '1') return true;
        bool tmp = true;
        for (int i = 0; i < s.length(); i ++){
            if (s[i] == '1' && tmp) continue;
            else if (s[i] == '0') {
                tmp = false;
            }
            else if (s[i] == '1' && !tmp) return false;
        }
        return true;
        
    }
};


int main() {
    Solution sol;
    bool ans = sol.checkOnesSegment("1111");
    cout << ans << endl;
    system("pause");
    return 0;
}

