/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-04-05 14:50:07
 * @LastEditTime: 2021-04-06 14:54:56
 * @FilePath: \Leetcode\weekcom\LCCUP2021 春季赛 个人\t4.cpp
 */
class Solution
{
public:
    int magicTower(vector<int>& nums) 
	{
		int blood=0;
		int harm=0;
		int d=0;
		priority_queue<int> q;
		int ret=0;
		for (int val:nums)
			if (val>0)
				blood+=val;
			else
			{
				val=-val;
				q.push(val);
				harm+=val;
				while (!q.empty() && blood<harm)
				{
					int key=q.top();
					q.pop();
					harm-=key;
					d+=key;
					++ret;
				}
			}
		return (blood>=harm+d)?ret:-1;
	}
};