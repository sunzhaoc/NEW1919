/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-20 22:22:25
 * @LastEditTime: 2021-03-21 10:16:49
 * @FilePath: \Leetcode\5693.Second Largest Digit in a String.cpp
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
MEMORY: 6.8MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021-03-20 22:40:00
Description: 
*/

class Solution {
public:
    int secondHighest(string s) {
        if (s.length() == 1) return -1;
        unordered_map<int, int> map;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                map[s[i] - '0'] ++;
            }
        }
        if (map.size() < 2) return -1;
        int id = 0;
        for (int i = 9; i >= 0; i --) {
            if (map.count(i)) id ++;
            if (id == 2) return i;
        }
        return -1;
    }
};



int main() {
    Solution sol;
    int ans = sol.secondHighest("ck077");
    cout << ans << endl;
    system("pause");
    return 0;
}