/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-04-27 22:50:58
 * @LastEditTime: 2021-04-27 23:26:13
 * @FilePath: \Leetcode\DataStructure\SA.cpp
 */

#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-8;	//终止温度 
double y;

double func(double x) {       //计算函数值 
	return 6*pow(x,7.0) + 8*pow(x, 6.0) + 7*pow(x,3.0) + 5*pow(x,2.0) - y*x;
}

double solve() {
	double temperature = 100;         // 初始温度
	double delta = 0.98;   // 降温系数 
	double x = 50.0;        // x的初始值 
	double now = func(x);  // 计算初始函数值 
	double ans = now;       // 返回值 
    
	while(temperature > eps) {         // eps是终止温度 
		int f[2] = {1, -1};
		double newx = x + f[rand() % 2] * temperature;    //按概率改变x，随T的降温而减少
        cout << abs(newx - x) << endl;
		if(newx >= 0 && newx <= 100) {
			double next = func(newx);
			ans = min(ans, next);
			if(now - next > eps) {  // next 是一个更小值
                x = newx; 
                now = next;    // 更新x 
            }     
		}
		temperature *= delta;
	}
    return ans;
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%lf", &y);
		printf("%.4f\n", solve());
	}
    system("pause");
	return 0; 
}
