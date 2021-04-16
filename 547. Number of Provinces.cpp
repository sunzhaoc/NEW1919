/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-07 09:23:08
 * @LastEditTime: 2021-01-07 09:58:14
 * @FilePath: \Leetcode\547.Number of Provinces.cpp
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
RESULT: Accept
TIME:     52ms    BEAT: 91.50%    O(n) = 
MEMORY: 14.6MB    BEAT:  6.20%    O(n) = 
Description: 并查集。
*/

class Solution {
public:
    vector<int> parent;

    int find(int index) {
        if (parent[index] != index) parent[index] = find(parent[index]);
        return parent[index];
    }

    void combine(int index1, int index2) {
        parent[find(index1)] = find(index2);
    }

    int findCircleNum(vector<vector<int>> isConnected) {

        int provinces = isConnected.size();

        for (int i = 0; i < provinces; i ++) parent.emplace_back(i);
        
        for (int i = 0; i < provinces; i ++) {
            for (int j = i + 1; j < provinces; j ++) {
                if (isConnected[i][j] == 1) {
                    combine(i, j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < provinces; i ++) {
            if (parent[i] == i) res ++;
        }
        return res;
    }
};


int main() {
    Solution sol;
    auto ans = sol.findCircleNum({{1,1,0},{1,1,0},{0,0,1}});
    cout << ans << endl;
    system("pause");
    return 0;
}
