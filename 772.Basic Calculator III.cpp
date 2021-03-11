/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-10 09:37:40
 * @LastEditTime: 2021-03-10 10:49:42
 * @FilePath: \Leetcode\772.Basic Calculator III.cpp
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
TIME:     24ms    BEAT:  9.25%    O(n) = 
MEMORY: 21.7MB    BEAT: 13.88%    O(n) = 
USED TIME: 01:04:20
LAST EDIT TIME: 2021年3月10日9:38:8
Description: 我真NB。这都能写出来。 回溯括号里的。
*/

class Solution {
public:
    int calculate(string s) {
        int res = trackBack(s, 0, s.length() - 1);
        return res;
    }

    int trackBack(string& s, int start, int end) {
        int i = start;
        long res = 0;
        int point = 0;
        stack<int> opts;
        stack<int> nums;
        opts.push(1);
    
        while (i <= end) {
            if (s[i] == ' ') i ++;
            else if (s[i] == '+') {
                opts.push(1);
                i ++;
            }
            else if (s[i] == '-') {
                opts.push(-1);
                i ++;
            }
            else if (s[i] == '*') {
                point = 1;
                i ++;
            }
            else if (s[i] == '/') {
                point = 2;
                i ++;
            }
            else if (s[i] == '(') {
                stack<int> brackLeft;
                brackLeft.push(i);
                int brackId = i;
                while (!brackLeft.empty()) {
                    brackId ++;
                    if (s[brackId] == '(') brackLeft.push(brackId);
                    else if (s[brackId] == ')') brackLeft.pop();
                }
                int tmp = trackBack(s, i + 1, brackId - 1);

                if (point == 1) {
                    tmp *= nums.top();
                    nums.pop();
                    point = 0;
                }
                else if (point == 2) {
                    tmp = nums.top() / tmp;
                    nums.pop();
                    point = 0;
                }
                nums.push(tmp);

                i = brackId + 1;
            }
            else {
                long tmp = 0;
                while (i <= end && s[i] >= '0' && s[i] <= '9') {
                    tmp = tmp * 10 + s[i] - '0';
                    i ++;
                }
                if (point == 1) {
                    tmp *= nums.top();
                    nums.pop();
                    point = 0;
                }
                else if (point == 2) {
                    tmp = nums.top() / tmp;
                    nums.pop();
                    point = 0;
                }
                nums.push(tmp);
            }
        }

        while (!opts.empty()) {
            res += opts.top() * nums.top();
            opts.pop();
            nums.pop();
        }
        
        return res;
    }
};


int main() {
    Solution sol;
    int ans = sol.calculate("6-4/2");
    cout << ans << endl;
    system("pause");
    return 0;
}