/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-21 10:11:24
 * @LastEditTime: 2021-03-21 14:33:14
 * @FilePath: \Leetcode\demo2.cpp
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
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        struct cmp1
        {
            bool operator() (const pair<long long, int>& x, const pair<long long, int>& y) {
                return x.second > y.second;
            }
        };

        struct cmp2
        {
            bool operator() (const pair<long long, int>& x, const pair<long long, int>& y) {
                return x.second < y.second;
            }
        };

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp1> sell; // 小
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp2> buy; // 大
        for (int i = 0; i < orders.size(); i ++) {

            if (orders[i][2] == 0) {
                
                while (!sell.empty() && sell.top().second <= orders[i][0] && orders[i][1] > 0) {
                    long long A = sell.top().first; // mount
                    int B = sell.top().second; // price
                    sell.pop();
                    if (A > orders[i][1]) {
                        sell.push({A - orders[i][1], B});
                        orders[i][1] = 0;
                        break;
                    }
                    else if (A == orders[i][1]) {
                        orders[i][1] = 0;
                        break;
                    }
                    else {
                        orders[i][1] -= A;
                    }
                }
                if (orders[i][1] > 0) buy.push({orders[i][1], orders[i][0]});
            }

            else {
                while (!buy.empty() && buy.top().second >= orders[i][0] && orders[i][1] > 0) {
                    long long A = buy.top().first;
                    int B = buy.top().second;
                    buy.pop();
                    if (A > orders[i][1]) {
                        buy.push({A - orders[i][1], B});
                        orders[i][1] = 0;
                        break;
                    }
                    else if (A == orders[i][1]) {
                        orders[i][1] = 0;
                        break;
                        }
                    else {
                        orders[i][1] -= A;
                    }
                }
                if (orders[i][1] > 0) sell.push({orders[i][1], orders[i][0]});
            }
        }

        long long res = 0;

        while (!sell.empty()) {
            res = (res + sell.top().first) % 1000000007;
            sell.pop();
        }
        while (!buy.empty()) {
            res = (res + buy.top().first) % 1000000007;
            buy.pop();
        }

        return res;
    }
};


int main() {
    Solution sol;
    // vector<vector<int>> nums = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    vector<vector<int>> nums = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
    // vector<vector<int>> nums = {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};
    int ans = sol.getNumberOfBacklogOrders(nums);
    cout << ans << endl; 
    system("pause");
    return 0;
}