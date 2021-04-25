/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-12 22:27:34
 * @LastEditTime: 2021-03-12 22:29:17
 * @FilePath: \Leetcode\面试题 01.02. 判定是否互为字符重排.cpp
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
MEMORY: 6.1MB    BEAT:  61.34%    O(n) = 
USED TIME: 00:51
LAST EDIT TIME: 2021年3月12日22:29:16
Description: 
*/

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};