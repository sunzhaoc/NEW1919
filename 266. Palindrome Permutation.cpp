/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-03 17:07:41
 * @LastEditTime: 2021-03-03 17:11:55
 * @FilePath: \Leetcode\266.Palindrome Permutation.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;


/*
RESULT: Accept
TIME:   0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6MB    BEAT:  92.99%    O(n) = 
USED TIME: 03:12
LAST EDIT TIME: 2021年3月3日17:11:27
Description: Easy.
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict;
        for (int i = 0; i < s.length(); i ++) {
            dict[s[i]] ++;
        }

        int tmp = 1;
        for (auto it = dict.begin(); it != dict.end(); it ++) {
            if (it->second % 2 == 1) tmp --;
            if (tmp < 0) return false;
        }

        return true;
    }
};