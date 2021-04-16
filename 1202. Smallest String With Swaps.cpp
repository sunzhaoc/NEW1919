/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-11 09:22:41
 * @LastEditTime: 2021-01-11 10:48:37
 * @FilePath: \Leetcode\1202.Smallest String With Swaps.cpp
 */
/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;


/*
RESULT: Accept
TIME:    352ms    BEAT: 48.40%    O(n) = 
MEMORY: 43.4MB    BEAT: 47.36%    O(n) = 
Description: 并查集。
*/

class Solution {
public:
    int pre[100001];

    int find(int root) {
        int son, tmp;
        son = root;

        // 找祖先结点
        while (root != pre[root]) {
            root = pre[root];
        }

        // 路径压缩
        while (son != root) {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        
        return root;
    }


    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size = s.length();
        for (int i = 0; i < size; i ++) {
            pre[i] = i;
        }
        
        for (auto item: pairs) {
            pre[find(item[0])] = find(item[1]);
        }

        vector<vector<char>> v(size);

        // 扎堆分类
        for (int i = 0; i < size; i ++) {
            v[find(i)].push_back(s[i]);
        } 

        string res;

        for (int i = 0; i < size; i ++) {
            sort(v[i].rbegin(), v[i].rend());
        }

        for (int i = 0; i < size; i ++) {
            res += v[pre[i]].back();
            v[pre[i]].pop_back();
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> pairs = {{0,3}, {1,2}};
    string ans = sol.smallestStringWithSwaps("dcab", pairs);
    cout << ans << endl;
    system("pause");
    return 0;
}

// @lc code=end

