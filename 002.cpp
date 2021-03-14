/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-14 10:12:55
 * @LastEditTime: 2021-03-14 10:48:32
 * @FilePath: \Leetcode\002.cpp
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



class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> dp1 = edges[0];
        vector<int> dp2 = edges[1];
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 2; j ++) {
                if (dp1[i] == dp2[j]) return dp1[i];
            }
        }
        return 0;
        
    }
};


int main() {
    Solution sol;
    ans = sol.();
    cout << ans << endl;
    system("pause");
    return 0;
}

