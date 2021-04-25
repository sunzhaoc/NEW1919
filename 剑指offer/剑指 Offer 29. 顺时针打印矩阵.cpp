/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2020-12-04 15:04:14
 * @LastEditTime: 2020-12-24 11:04:16
 * @FilePath: \Leetcode\剑指 Offer 29. 顺时针打印矩阵.cpp
 */
#include <vector>
#include <iostream>
using namespace std;

/*
RESULT: Accept
TIME:     28ms    BEAT: 24.45%    O(n) = mn
MEMORY: 10.5MB    BEAT:  5.01%    O(n) = 1?
Description: 使用四条边来定义边界，当 left > right 或 up > down 时，退出。
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        int up = 0, down = (int)matrix.size() - 1, left = 0, right = (int)matrix[0].size() - 1;
        vector<int> ans;
        
        while (1)
        {
            for (int i = left; i <= right; i ++)    ans.push_back(matrix[up][i]);
            up ++;
            if (up > down) break;

            for (int i = up; i <= down; i ++)   ans.push_back(matrix[i][right]);
            right --;
            if (left > right) break;

            for (int i = right; i >= left; i --)    ans.push_back(matrix[down][i]);
            down --;
            if (up > down) break;
            
            for (int i = down; i >= up; i --)   ans.push_back(matrix[i][left]);
            left ++;
            if (left > right) break;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     20ms    BEAT: 91.14%    O(n) = mn
MEMORY: 10.5MB    BEAT:  5.01%    O(n) = 1?
Description: 使用四个角的点的坐标来定义边界,用计数的方法来判断退出条件。
*/

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>> matrix) {
//         if (matrix.size() == 0 || matrix[0].size() == 0) return {};
//         vector<int> up_left = {0, 0}, up_right = {0, (int)matrix[0].size() - 1};
//         vector<int> down_left = {(int)matrix.size() - 1, 0}, down_right = {(int)matrix.size() - 1, (int)matrix[0].size() - 1};
//         int sum = matrix.size() * matrix[0].size(), num = 0;
//         vector<int> ans;
        
//         while (1)
//         {
//             for (int i = up_left[1]; i <= up_right[1]; i++){
//                 ans.push_back(matrix[up_left[0]][i]);
//                 num ++;
//             }
//             up_left[0]++;   
//             up_right[0]++;
//             if (num >= sum) break;

//             for (int i = up_right[0]; i <= down_right[0]; i++){
//                 ans.push_back(matrix[i][up_right[1]]);
//                 num ++;
//             }
//             up_right[1]--;
//             down_right[1]--;
//             if (num >= sum) break;

//             for (int i = down_right[1]; i >= down_left[1]; i--){
//                 ans.push_back(matrix[down_right[0]][i]);
//                 num ++;
//             }
//             down_right[0]--;
//             down_left[0]--;
//             if (num >= sum) break;

//             for (int i = down_left[0]; i >= up_left[0]; i--){
//                 ans.push_back(matrix[i][down_left[1]]);
//                 num ++;
//             }
//             down_left[1]++;
//             up_left[1]++;
//             if (num >= sum) break;
//         }
//         return ans;
//     }
// };


int main(){
    Solution sol;
    vector<int> ans = sol.spiralOrder({{1,2,3},{4,5,6},{7,8,9}});
    // vector<int> ans = sol.spiralOrder({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}