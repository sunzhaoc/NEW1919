/*
 * @Description: 
 * @Version: 1.0
 * @Author: Vicro
 * @Date: 2020-11-25 14:44:59
 * @LastEditTime: 2020-12-14 21:44:42
 * @FilePath: \Leetcode\649.Dota2 Senate.cpp
 */
/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参�??�?
 */
// @lc code=start
#include <iostream>
// #include <string>
using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {
        bool R = true, D = true;
        int person = 0;
        while (D && R)
        {
            R = false;
            D = false;
            for (int i = 0; i < senate.size(); i++)
            {
                if (senate[i] == 'R')
                {
                    R = true;
                    if (person < 0)
                        senate[i] = '0';
                    person++;
                }
                else if (senate[i] == 'D')
                {
                    D = true;
                    if (person > 0)
                        senate[i] = '0';
                    person--;
                }
            }
        }
        return person > 0 ? "Radiant" : "Dire";
    }
};


int main(){
    Solution sol1;
    string A;
    A = sol1.predictPartyVictory("RDDRRD");
    cout << A << endl;
    system("pause");
    return 0;
}
// @lc code=end

