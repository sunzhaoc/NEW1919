/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-01-11 16:26:33
 * @LastEditTime: 2021-01-11 16:30:52
 * @FilePath: \Leetcode\1720.Decode XORed Array.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


/*
RESULT: Accept
TIME:     80ms    BEAT: 100.00%    O(n) = 
MEMORY: 25.8MB    BEAT: 100.00%    O(n) = 
Description: 
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(int x: encoded) ans.push_back(ans.back() ^ x);
        return ans;
    }
};