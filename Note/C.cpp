/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-03-04 21:46:19
 * @LastEditTime: 2021-03-31 20:50:57
 * @FilePath: \Leetcode\STAR\C.cpp
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


// 快速计算x的二进制里有多少个1.
int function(int x) {
    int num = 0;
    for (int i = x; i; i >>= 1) num += i & 1;
    return num;
}


// 最大公约数
int gcd (int a, int b) {
    return b ? gcd(b, a % b) : a;
}


// 最小公倍数 = 两数乘积 / 最大公约数


// 判断一个数是否是素数。
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) return false;
    }
    return true;
}


// 二分查找 -- 标准版
bool binarySearch(vector<int> nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (nums[mid] == target) return true;
        else if (nums[mid] > target) r = mid - 1;
        else if (nums[mid] < target) l = mid + 1;
    }
    
    return false;
}


// 二分查找 - 
bool binarySearch(vector<int> nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (nums[mid] == target) return true;
        else if (nums[mid] >= target) r = mid;
        else if (nums[mid] < target) l = mid + 1;
    }

    if (nums[l] == target) return true;
    return false;
}


bool binarySearch(vector<int> nums, int target) {
    int l = 0, r = nums.size();

    while (l < r) {
        int mid = (r - l + 1) / 2 + l;
        if (nums[mid] == target) return true;
        else if (nums[mid] <= target) l = mid;
        else if (nums[mid] > target) r = mid - 1;
    }

    if (nums[r] == target) return true;
    return false;
}