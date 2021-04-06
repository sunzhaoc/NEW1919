/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-12 22:22:54
 * @LastEditTime: 2021-03-12 22:27:14
 * @FilePath: \Leetcode\面试题 01.01. 判定字符是否唯一.cpp
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
TIME:   0ms    BEAT: 100.00%    O(n) = 
MEMORY: 6MB    BEAT:  52.50%    O(n) = 
USED TIME: 02:45
LAST EDIT TIME: 2021年3月12日22:26:9
Description: 
*/

class Solution {
public:
    bool isUnique(string astr) {
        unordered_set<char> map;
        for (char s: astr) {
            if (map.find(s )!= map.end()) return false;
            else map.insert(s);
        }
        return true;
    }
};