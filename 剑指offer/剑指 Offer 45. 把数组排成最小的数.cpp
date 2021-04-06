/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-05 16:47:07
 * @LastEditTime: 2021-01-05 17:27:19
 * @FilePath: \Leetcode\剑指 Offer 45. 把数组排成最小的数.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
RESULT: Accept
TIME:     12ms    BEAT: 71.84%    O(n) = 
MEMORY: 11.6MB    BEAT: 36.69%    O(n) = 
USED TIME: 37:17
Description: Important！！！需要自定义排序规则。
*/

class Solution {
public:
    string minNumber(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);

        vector<string> store;
        string res = "";

        for (int i: nums) {
            store.push_back(to_string(i));
        }

        sort(store.begin(), store.end(), strCompare);
        
        for (string i: store) {
            res += i;
        }

        return res;
    }

    static bool strCompare(const string& s1, const string& s2) {
        string add1 = s1 + s2;
        string add2 = s2 + s1;
        return add1 < add2; // 升序排列
    }
};
