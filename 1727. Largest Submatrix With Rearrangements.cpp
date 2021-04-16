/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-18 10:42:10
 * @LastEditTime: 2021-01-18 11:13:24
 * @FilePath: \Leetcode\1727.Largest Submatrix With Rearrangements.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:    240ms    BEAT: 100.00%    O(n) = 
MEMORY: 66.1MB    BEAT: 100.00%    O(n) = 
LAST EDIT TIME: 2021-1-18 11:13:22
Description: 
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int ans = -1;
        vector<int> count(col);
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                count[j] = (matrix[i][j] ? count[j] + 1 : 0);
            }
            vector<int> tmp = count;
            sort(tmp.rbegin(), tmp.rend());
            for (int j = 0; j < col; j ++) {
                ans = max(ans, (j + 1) * tmp[j]);
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // vector<vector<int>> matrix = {{0,0,1}, {1,1,1}, {1,0,1}};
    vector<vector<int>> matrix = {{1, 0, 1, 0, 1}};
    int ans = sol.largestSubmatrix(matrix);
    cout << ans << endl;
    system("pause");
    return 0;
}