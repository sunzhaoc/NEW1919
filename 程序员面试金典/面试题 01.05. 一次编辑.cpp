/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-15 22:09:14
 * @LastEditTime: 2021-03-15 22:47:16
 * @FilePath: \Leetcode\demo.cpp
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
TIME:     4ms    BEAT: 74.85%    O(n) = 
MEMORY: 6.1MB    BEAT: 82.50%    O(n) = 
USED TIME: 24:14
LAST EDIT TIME: 2021年3月15日22:46:27
Description: 纠结于length的返回值的问题上。
*/

class Solution {
public:
    bool oneEditAway(string first, string second) {

        if (abs((int)first.length() - (int)second.length()) > 1) return false;
        
        if (first.length() == second.length()) {
            int cnt = 0;
            for (int i = 0; i < first.length(); i ++) {
                if (first[i] != second[i]) cnt ++;
                if (cnt > 1) return false;
            }
        }
        else {
            if (first.size() == 0 || second.size() == 0) return true;
            int i = 0, j = 0, cnt = 0;
            while (i < first.size() && j < second.size()) {
                if (first[i] != second[j]) {
                    first.size() > second.size() ? i ++ : j ++;
                    cnt ++;
                    if (cnt > 1) return false;
                    continue;
                }
                i ++;
                j ++;
                
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    bool ans = sol.oneEditAway("a", "ab");
    cout << ans << endl;
    system("pause");
    return 0;
}
