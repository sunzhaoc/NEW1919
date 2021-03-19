/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-19 09:11:50
 * @LastEditTime: 2021-03-19 09:27:59
 * @FilePath: \Leetcode\1603.Design Parking System.cpp
 */
/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start


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
TIME:     64ms    BEAT: 87.38%    O(n) = 
MEMORY: 32.3MB    BEAT: 59.35%    O(n) = 
USED TIME: 14:09
LAST EDIT TIME: 2021年3月19日9:27:19
Description: switch语句不太熟。
*/

class ParkingSystem {
public:
    int bigStop = 0, mediumStop = 0, smallStop = 0;
    int bigNum, mediumNum, smallNum;

    ParkingSystem(int big, int medium, int small) {
        bigNum = big, mediumNum = medium, smallNum = small;
    }

    bool addCar(int carType) {
        switch (carType)
        {
        case 1:
            if (bigStop + 1 <= bigNum) {
                bigStop ++;
                return true;
            }
            break;
        case 2:
            if (mediumStop + 1 <= mediumNum) {
                mediumStop ++;
                return true;
            }
            break;
        case 3:
            if (smallStop + 1 <= smallNum) {
                smallStop ++;
                return true;
            }
            break;
        return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

