/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-15 22:04:56
 * @LastEditTime: 2021-03-15 22:08:23
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
TIME:     4ms    BEAT: 32.09%    O(n) = 
MEMORY: 6.2MB    BEAT: 40.55%    O(n) = 
USED TIME: 02:39
LAST EDIT TIME: 2021年3月15日22:8:9
Description: 
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict;
        for (char &a: s) {
            dict[a] ++;
        }
        
        int tmp = 0;
        for (auto i = dict.begin(); i != dict.end(); i ++) {
            if (i->second % 2 == 1) tmp += 1;
            if (tmp > 1) return false;
        }
        return true;
    }
};
