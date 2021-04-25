/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-05 10:22:59
 * @LastEditTime: 2021-01-05 11:12:02
 * @FilePath: \Leetcode\剑指 Offer 31. 栈的压入、弹出序列.cpp
 */
#include <stack>
#include <vector>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:   16ms    BEAT: 80.40%    O(n) = n
MEMORY: 15MB    BEAT: 82.48%    O(n) = n
USED TIME: 44:33
Description: 
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push_point = 0, pop_point = 0;
        stack<int> stack1;

        for (int i = 0; i < pushed.size(); i ++) {
            if (pushed[push_point] == popped[0]) {
                pop_point ++;
                push_point ++;
                break;
            }
            stack1.push(pushed[push_point]);
            push_point ++;
        }

        while (pop_point < popped.size()) {
            if (!stack1.empty() && popped[pop_point] == stack1.top()) {
                stack1.pop();
                pop_point ++;
            }
            else if (push_point <= pushed.size() - 1 && pushed[push_point] == popped[pop_point]) {
                push_point ++;
                pop_point ++;
            }
            else if (push_point <= pushed.size() - 1) {
                stack1.push(pushed[push_point]);
                push_point ++;
            }
            else return false;
        }
        return true;
    }
};


int main() {
    Solution sol;
    // vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    // vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 3, 5, 1, 2};
    // vector<int> pushed = {1, 0}, popped = {1, 0};
    // vector<int> pushed = {0, 2, 1}, popped = {0, 1, 2};
    vector<int> pushed = {2, 0, 1}, popped = {2, 1, 0};

    bool ans = sol.validateStackSequences(pushed, popped);
    cout << ans << endl;
    system("pause");
    return 0;
}