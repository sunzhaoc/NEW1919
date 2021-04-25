/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-15 22:47:58
 * @LastEditTime: 2021-03-15 22:58:08
 * @FilePath: \Leetcode\demo.cpp
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
TIME:     8ms    BEAT: 91.69%    O(n) = 
MEMORY: 7.2MB    BEAT: 73.53%    O(n) = 
USED TIME: 09:26
LAST EDIT TIME: 2021年3月15日22:57:51
Description: 
*/

class Solution {
public:
    string compressString(string S) {
        string T = "";
        
        int cnt = 0;
        char ch = S[0];
        for (int i = 0; i < S.length(); i ++) {
            if (i == 0) {
                cnt = 1;
            }

            else {
                if (S[i] == ch) {
                    cnt ++;
                }
                else {
                    T += (ch + to_string(cnt));
                    cnt = 1;
                    ch = S[i];
                }
            }
        }

        T += (ch + to_string(cnt));
        return T.size() < S.size() ? T : S;
    }
};