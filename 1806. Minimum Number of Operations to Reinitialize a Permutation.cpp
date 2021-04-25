/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-30 12:33:18
 * @LastEditTime: 2021-03-30 15:10:50
 * @FilePath: \Leetcode\1806.Minimum Number of Operations to Reinitialize a Permutation.cpp
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
TIME:     92ms    BEAT: 6.01%    O(n) = 
MEMORY: 57.3MB    BEAT: 5.04%    O(n) = 
LAST EDIT TIME: 2021年3月30日15:3:14
Description: Y总。
*/

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> q;
        for (int i = 0; i < n; i ++) q.push_back(i);
        int cnt = 0;
        while (1) {
            cnt ++;
            work(q);
            if (check(q)) break;
        }
        return cnt;
    }

    void work(vector<int>& q) {
        vector<int> w;
        for (int i = 0; i < q.size(); i += 2) w.push_back(q[i]);
        for (int i = 1; i < q.size(); i += 2) w.push_back(q[i]);
        q = w;
    }

    bool check(vector<int>& q) {
        for (int i = 0; i < q.size(); i ++) {
            if (q[i] != i) return false;
        }
        return true;
    }
};


/*
RESULT: Accept
TIME:    56ms    BEAT: 10%    O(n) = 
MEMORY: 6.5MB    BEAT: 54%    O(n) = 
LAST EDIT TIME: 2021年03月30日12:58:47
Description: 
*/

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> prem(n);
        for (int i = 0; i < n; i ++) prem[i] = i;
        vector<int> arr(n);
        int res = 0;
        bool flag = true;
        vector<int> pre_num = prem;
        while (1) {
            res ++;
            flag = true;
            for (int i = 0; i < n; i ++) {
                if (i % 2 == 0) arr[i] = prem[i / 2];
                else arr[i] = prem[n / 2 + (i - 1) / 2];
                
                if (arr[i] != pre_num[i]) flag = false;
            }
            prem = arr;
            if (flag) return res;
        }
        return -1;
    }
};


int main() {
    Solution sol;
    int ans = sol.reinitializePermutation(6);
    cout << ans << endl;
    system("pause");
    return 0;
}
