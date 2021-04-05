/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 14:48:06
 * @LastEditTime: 2021-04-05 17:24:41
 * @FilePath: \Leetcode\weekcom\t3.cpp
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



class Solution {
public:
    int magicTower(vector<int>& nums) {
        int blood = 1;
        int hurt = 0;
        deque<int> room;
        for (int num: nums) {
            if (num >= 0) blood += num;
            else {
                hurt += num;
            }
            room.push_back(num);
        }
        if (blood + hurt <= 0) return -1;
        
        blood = 1;
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        while (room.size()) {

            blood += room.front();

            if (blood > 0) {
                room.pop_front();
                if (room.front() < 0) q.push(room.front());
            }
            else {
                while (blood <= 0) {
                    blood -= q.top();
                    // room.push_back(q.top());
                    q.pop();
                    cnt ++;
                }
                if (room.front() < 0) q.push(room.front());
            
                room.pop_front();
            }
        }
        return cnt;
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
