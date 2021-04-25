/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-03 22:22:00
 * @LastEditTime: 2021-04-04 14:40:04
 * @FilePath: \Leetcode\demo01.cpp
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

typedef vector<int> VI;
typedef vector<int> VII;

/*
RESULT: Accept
Description: 比赛写的。
*/

class Solution {
public:
    bool squareIsWhite(string s) {
        if ((((s[0] - 'a' + 1) % 2) + (s[1] % 2)) % 2 == 0) return false;
        return true;
    }
};


/*
RESULT: Accept
Description: 比赛写的。
*/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = (coordinates[0] - 'a' + 1) % 2;
        int y = coordinates[1] % 2;
        
        if ((x + y) % 2 == 0)  return false;
        else return true;
    }
};
