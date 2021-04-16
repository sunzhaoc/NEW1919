/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Vicro
 * @Date: 2021-01-19 20:42:04
 * @LastEditTime: 2021-01-20 17:09:07
 * @FilePath: \Leetcode\307.Range Sum Query - Mutable.cpp
 */
/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;


/*
RESULT: Accept
TIME:     444ms    BEAT: 16.93%    O(n) = 
MEMORY: 149.5MB    BEAT:  5.01%    O(n) = 
LAST EDIT TIME:2021年1月20日17:8:34
Description: 线段树的另一种写法。
https://leetcode-cn.com/problems/range-sum-query-mutable/solution/xian-duan-shu-zu-shou-hui-tu-xiang-yi-qing-er-chu-/
*/

class NumArray {
public:
    int n;
    vector<int> _nums;
    vector<long> _sums;

    NumArray(vector<int>& nums) {
        n = nums.size();
        _nums = nums;
        _sums.resize(2 * n);

        for (int i = 0; i < n; i ++) {
            _sums[i + n] = nums[i];
        }

        // 数组第一个为NULL。
        for (int i = n - 1; i > 0; i --) {
            _sums[i] = _sums[i * 2] + _sums[i * 2 + 1];
        }
    }
    
    void update(int index, int val) {
        int num_index = index + n;
        int diff = val - _nums[index];
        _nums[index] = val;
        
        while (num_index > 0) {
            _sums[num_index] += diff;
            num_index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int ans = 0;
        
        while (left <= right) {
            // 写得那么玄幻。。。
            // if (left & 1) {
            if (left % 2 == 1) {
                ans += _sums[left];
                left ++;
            }

            // if (!(right & 1)) {
            if (right % 2 == 0) {
                ans += _sums[right];
                right --;
            }

            left /= 2;
            right /= 2;
        }
        return ans;
    }
};


/*
RESULT: Accept
TIME:     508ms    BEAT: 10;72%    O(n) = 
MEMORY: 149.4MB    BEAT:  5.01%    O(n) = 
LAST EDIT TIME: 2021年1月20日17:8:30
Description: 线段树。线段数组。
https://www.bilibili.com/video/BV1cb411t7AM?from=search&seid=18208041544899466251
这个视频强推。
*/

// class NumArray {
// public:    
//     vector<int> tree;
//     vector<int> arr;

//     void build_tree(int node, int start, int end) {
//         if (start == end) {
//             tree[node] = arr[start];
//             return;
//         }

//         int mid = (end - start) / 2 + start;
//         int left_node = 2 * node + 1;
//         int right_node = 2 * node + 2;

//         build_tree(left_node, start, mid);
//         build_tree(right_node, mid + 1, end);
//         tree[node] = tree[left_node] + tree[right_node];
//     }

//     NumArray(vector<int>& nums) {
//         arr = nums;
//         // 线段树空间一般开辟大小为 4n。
//         tree.resize(4 * nums.size(), 0);
//         build_tree(0, 0, nums.size() - 1);
//     }


//     void update_tree(int node, int start, int end, int index, int val) {
//         if (start == end) { 
//             arr[index] = val;
//             tree[node] = val;
//             return;
//         }

//         int mid = (end - start) / 2 + start;
//         int left_node = node * 2 + 1;
//         int right_node = node * 2 + 2;

//         if (index >= start && index <= mid) {
//             update_tree(left_node, start, mid, index, val);
//         }
//         else {
//             update_tree(right_node, mid + 1, end, index, val);
//         }

//         tree[node] = tree[left_node] + tree[right_node];
//     }

//     void update(int index, int val) {
//         update_tree(0, 0, arr.size() - 1, index, val);
//     }


//     int sumTree(int node, int start, int end, int L, int R) {
//         if (R < start || L > end) {
//             return 0;
//         }
//         // 如果不加||后面的条件，会遍历到根结点。
//         else if (start == end || (start >= L && end <= R)) {
//             return tree[node];
//         }
//         int mid = (end - start) / 2 + start;
//         int left_node = node * 2 + 1;
//         int right_node = node * 2 + 2;
//         int sum_left = sumTree(left_node, start, mid, L, R);
//         int sum_right = sumTree(right_node, mid + 1, end, L, R);
//         return sum_left + sum_right;
//     }

//     int sumRange(int left, int right) {
//         return sumTree(0, 0, arr.size() - 1, left, right);
//     }
// };


/*
RESULT: Time Out
TIME:   ms    BEAT: %    O(n) = 
MEMORY: MB    BEAT: %    O(n) = 
USED TIME: 20:51
LAST EDIT TIME: 2021年1月19日21:6:27
Description: 前缀和。不能用和304题相似的方法。
*/

// class NumArray {
// public:
//     vector<int> sum;
//     NumArray(vector<int>& nums) {
//         sum.resize(nums.size() + 1, 0);

//         for (int i = 0; i < nums.size(); i ++) {
//             sum[i + 1] = sum[i] + nums[i];
//         }

//         int V =1;
//     }

//     void update(int index, int val) {
//         int tmp = sum[index] + val - sum[index + 1];
//         for (int i = index + 1; i < sum.size(); i ++) {
//             sum[i] += tmp;
//         }
//     }

//     int sumRange(int left, int right) {
//         return sum[right + 1] - sum[left]; 
//     }
// };


int main() {
    vector<int> nums = {1,3,5,7,9,11};
    NumArray sol(nums);
    // int ans = sol.sumRange(4,6);
    // cout << ans << endl;
    sol.update(4, 6);
    int ans = sol.sumRange(2,5);
    cout << ans << endl;
    system("pause");
    return 0;
}


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

// @lc code=end

