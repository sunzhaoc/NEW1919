/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-03 22:22:00
 * @LastEditTime: 2021-04-04 00:02:20
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 
Description: 
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
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
LAST EDIT TIME: 
Description: 
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
