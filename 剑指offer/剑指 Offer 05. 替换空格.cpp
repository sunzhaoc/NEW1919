/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-12-03 21:50:54
 * @LastEditTime: 2020-12-03 22:11:32
 * @FilePath: \Leetcode\剑指 Offer 05. 替换空格.cpp
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;



/*
RESULT: Accept
TIME: 0ms BEAT: 100.00%
MEMORY: 6.5MB BEAT: 14.32%
Description: 从前往后遍历数组，开辟一个新的字符串，遇到空格就append %20，希望能在原来的字符串上进行修改。
*/
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ') res.append("%20");
            else res += s[i];
        }
        return res;
    }
};


int main(){
    Solution sol;
    string A = sol.replaceSpace("We are happy.");
    cout << A << endl;
    system("pause");
    return 0;
}
