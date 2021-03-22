/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-21 20:39:59
 * @LastEditTime: 2021-03-21 21:41:15
 * @FilePath: \Leetcode\deno.cpp
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
    int isPalindrome(int w, int n, vector<int> x, vector<int> y) {
        struct cmp
        {
            bool operator() (const pair<int, int>& x, const pair<int, int>& y) {
                return x.first > y.first;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap;
        
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            minHeap.push({y[i], x[i]});
            sum += y[i];
        }

        if (sum < w) // 直接return中位数。
        int A = 0;
        vector<int> tmp;
        while (w < sum) {
            if (minHeap.top().first == minHeap.top().second) {
                tmp.push_back(minHeap.top().first);
                minHeap.pop();
            }
            else {
                if (minHeap.top().first - minHeap.top().second > sum - w){
                    minHeap.top().first -= (sum - w); //不能直接赋值，用中间变量接一下。
                    break;
                }
                else if (minHeap.top().first - minHeap.top().second == sum - w){
                    minHeap.top().first =  minHeap.top().second;
                    break;
                }
                else {
                    tmp.push_back(minHeap.top().second);
                    sum -= (minHeap.top().first - minHeap.top().second );
                    minHeap.pop();
                }
            }
        } 


        // 最后一求。
        

    }
};



#include <iostream>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while (T --)
    {
        int n = 0, res = 0;
        cin >> n;
        while (n)
        {
            if (n % 3 == 0) n /= 3, res ++;
            else if ((n - 1) % 3 == 0 && n % 4 != 0) n -= 1, res ++;
            else if (n % 2 == 0) n /= 2, res ++;
            else 
            {
                n -= 1;
                res ++;
            }
        }
        cout << res << endl;
    }
    return 0;
}