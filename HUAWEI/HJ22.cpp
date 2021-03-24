/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-03-23 21:31:50
 * @LastEditTime: 2021-03-23 21:31:50
 * @FilePath: \Leetcode\HUAWEI\HJ22.cpp
 */
#include <iostream> 
#include <vector>
using namespace std;

int main() {
    int emptyBottle = 0;
    while (cin >> emptyBottle) {
        if (emptyBottle == 0) break;
        int bottle = 0;
        while (emptyBottle >= 3) {
            bottle += emptyBottle / 3;
            emptyBottle = emptyBottle % 3 + emptyBottle / 3;
        }
        if (emptyBottle == 2) bottle ++;
        cout << bottle << endl;
    }
}