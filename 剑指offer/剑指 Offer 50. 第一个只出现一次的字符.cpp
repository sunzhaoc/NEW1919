/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 19:27:05
 * @LastEditTime: 2021-01-05 19:49:45
 * @FilePath: \Leetcode\剑指 Offer 50. 第一个只出现一次的字符.cpp
 */
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;


/*
RESULT: Accept
TIME:   172ms    BEAT: 28.67%    O(n) = n
MEMORY:  11MB    BEAT: 18.38%    O(n) = 1
USED TIME: 15:27 
Description: 
*/

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, bool> map;
        for (char i: s) {
            map[i] = map.find(i) == map.end();
        }
        for (char i: s) {
            if (map[i]) return i;
        }
        return ' ';
    }
};


int main() {
    Solution sol;
    char ans = sol.firstUniqChar("abaccdeff");
    cout << ans << endl;
    system("pause");
    return 0;
}