/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-27 13:31:20
 * @LastEditTime: 2021-05-27 13:38:42
 * @FilePath: \Leetcode\AcWing\873. 欧拉函数.cpp
 */

/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 */

# include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    while (n --) {
        cin >> a;
        long long res = a;
        for (int i = 2; i <= a / i; i ++) {
            if (a % i == 0) {
                while (a % i == 0) a /= i;
                res = res / i * (i - 1);
            }
        }
        if (a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
    system("pause");
    return 0;
}