/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-05 16:50:39
 * @FilePath: \Leetcode\weekcom\t2.cpp
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

// typedef vector<LL> VI;
// typedef vector<vector<LL>> VVI;
// typedef vector<string> VS;
// typedef vector<vector<string>> VVS;
typedef long long LL;
const int N = 9;
class Solution {
public:
    int orchestraLayout(LL num, LL xPos, LL yPos) {
        if (num <1 || xPos < 0 || yPos < 0) return - 1;
        int ans = (getPoLLValue(num, yPos + 1, xPos + 1)) % 9;
        // LL ans = (getPoLLValue(4,1,2)) % 9;
        // LL ans = (getPoLLValue(4,2 + 1,1 + 1)) % 9;
        return ans;
    }
    int getPoLLValue(LL n,  LL _x, LL _y) {
        const long ulimit = n - 1, x = _x - 1, y = _y - 1;
        long i, minIdx = -1, maxIdx = -1;
        long sval = 0, result = 0;
        minIdx = min(min(x, ulimit - x), min(y, ulimit - y));
        sval = 1;
        for(i = 0; i < minIdx; ++i){
            sval +=  ((ulimit - i * 2)% N * 4) % N;
            sval %= N;
        } 
        
        maxIdx = ulimit - minIdx;
        if(y == minIdx){
            result = sval + x - minIdx;
        }
        else if(x == maxIdx){
            result = sval + ((maxIdx - minIdx)) % N + (y - minIdx); 
        }
        else if(y == maxIdx){
            result = (sval + ((maxIdx - minIdx) * 2) % N) % N +  maxIdx - x; 
        }
        else if (x == minIdx){
            result = (sval + ((maxIdx - minIdx) * 3) % N) % N + maxIdx - y; 
        }
        return result;
    }
};

int main() {
    Solution sol;
    for (int i = 100000; i < 100000+100; i ++) {
        for (int j = 100000; j < 100000+100; j ++) {
            int ans = sol.orchestraLayout(10000006,i,j);
            cout << ans << endl;
        }
    }

    // cout << ans << endl;
    system("pause");
    return 0;
}
