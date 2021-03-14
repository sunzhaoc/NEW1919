/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-14 10:13:03
 * @LastEditTime: 2021-03-14 11:48:25
 * @FilePath: \Leetcode\003.cpp
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

// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         vector<double> tmp(classes.size());
//         for (int k = 0; k < extraStudents; k ++) {
//             for (int i = 0; i < classes.size(); i ++) {
//                 tmp[i] = ((classes[i][0] + 1) * 1.0 / (classes[i][1] + 1) - classes[i][0] * 1.0/ classes[i][1]);
//             }
//             double maxNum = *max_element(tmp.begin(), tmp.end());
//             int index;
//             for (int i = 0; i < tmp.size(); i ++) {
//                 if (tmp[i] == maxNum) {
//                     index = i;
//                     break;
//                 }
//             }
//             classes[index][0] += 1;
//             classes[index][1] += 1;
//         }
//         double res = 0;
//         for (int i = 0; i < classes.size(); i ++) {
//             res += classes[i][0] * 1.0/ classes[i][1];
//         }
//         res = res / (classes.size());
//         return res;
        
//     }
// };


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& tmp, int extraStudents) {
        
        vector<vector<double>> classes(tmp.size(), vector<double>(tmp[0].size()));
        for (int i = 0; i < tmp.size(); i ++) {
            classes[i] = {1.0*tmp[i][0], 1.0*tmp[i][1]};
        }

        for (int k = 0; k < extraStudents; k ++) {
            
            // for (int i = 0; i < classes.size(); i ++) {
            //     if (k == 0)                classes[i].emplace_back(((classes[i][0] + 1) / (classes[i][1] + 1) - classes[i][0] / classes[i][1]));
            //     else  classes[i][2] = (((classes[i][0] + 1) / (classes[i][1] + 1) - classes[i][0] / classes[i][1]));
            // }
            if (k == 0){
            sort(classes.begin(), classes.end(), [](const vector<double> &x, const vector<double> &y) {
                return (((x[0] + 1) / (x[1] + 1)) - (x[0] / x[1])) > (((y[0] + 1) / (y[1] + 1)) - (y[0] / y[1]));
            });
            }
            else {
                sort(classes.begin(), classes.begin() + , [](const vector<double> &x, const vector<double> &y) {
                return (((x[0] + 1) / (x[1] + 1)) - (x[0] / x[1])) > (((y[0] + 1) / (y[1] + 1)) - (y[0] / y[1]));
            });
            }

            classes[0][0] += 1;
            classes[0][1] += 1;
        }
        double res = 0;
        for (int i = 0; i < classes.size(); i ++) {
            res += classes[i][0] / classes[i][1];
        }
        res = res / (classes.size());
        return res;
        
    }
};



int main() {
    Solution sol;
    // vector<vector<int>> nums = {{1,2}, {3,5}, {2,2}};
    
    // double ans = sol.maxAverageRatio(nums, 2);
    vector<vector<int>> nums = {{2,4}, {3,9}, {4,5}, {2, 10}};
    
    double ans = sol.maxAverageRatio(nums, 4);
    cout << ans << endl;
    system("pause");
    return 0;
}


