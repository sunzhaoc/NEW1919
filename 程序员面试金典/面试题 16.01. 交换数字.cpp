/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-19 15:43:47
 * @LastEditTime: 2021-04-19 15:44:30
 * @FilePath: \Leetcode\程序员面试金典\面试题 16.01. 交换数字.cpp
 */

#include <bits/stdc++.h>
using namespace std;

/*
RESULT: Accept
TIME:     0ms    BEAT: 100.00%    O(n) = 1
MEMORY: 6.8MB    BEAT:  96.68%    O(n) = 1
LAST EDIT TIME: 2021年4月19日15:44:0
Description: 不会
*/

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
};