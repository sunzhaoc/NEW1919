/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-06 14:59:53
 * @FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\LCP 30. 魔塔游戏.cpp
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
typedef vector<vector<int>> VVI;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef long long LL;


/*
RESULT: Accept
TIME:   196ms    BEAT: %    O(n) = 
MEMORY:  70MB    BEAT: %    O(n) = 
LAST EDIT TIME: 2021年4月6日14:59:56
Description: 思路一样，但比赛的时候没写出来。
*/

class Solution {
public:
    int magicTower(vector<int>& nums) {
        LL blood = 0;
        LL harm = 0;
        LL backHarm = 0;
        priority_queue<int> q;
        int ret = 0;
        for (int val: nums) {
            if (val > 0) blood += val;
            else {
                val = -val;
                q.push(val);
                harm += val;
                while (q.size() && blood < harm) {
                    harm -= q.top();
                    backHarm += q.top();
                    q.pop();
                    ret ++;
                }
            }
        }
        return harm + backHarm <= blood ? ret : -1;
    }
};


int main() {
    Solution sol;
    VI nums = {100,100,100,-60,-140,-50,-50,-250,100,150};
    // VI nums = {-200,-300,400,0};
    int ans = sol.magicTower(nums);
    cout << ans << endl;
    system("pause");
    return 0;
}
