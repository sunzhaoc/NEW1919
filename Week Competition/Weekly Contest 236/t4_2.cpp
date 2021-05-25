/*
 * @Description: 
 * @Version: 1.0
 * @Autor: 冰凝水
 * @Date: 2021-05-25 10:11:44
 * @LastEditTime: 2021-05-25 10:11:44
 * @FilePath: \Leetcode\Week Competition\Weekly Contest 236\t4_2.cpp
 */
class Solution {
public:

    const int M = 1024, INF = 1e8;
    int s[1024];

    int minChanges(vector<int>& nums, int k) {
        int n = nums.size(), m = (n+k-1)/k;
        vector<vector<int>> f(k+1,vector<int>(M,INF));
        int sum = 0, minv = INF;
        f[0][0] = 0;
        for(int i = 1; i<= k; i++) {
            int len = m;
            memset(s, 0, sizeof s);
            if(n % k && n % k < i) len--;
            for(int j = 0; j<len ; j++)
                s[nums[j * k + i - 1]]++;
            int maxv = 0;
            for(int j = 0; j<M ; j++)
                if(s[j])
                maxv = max(maxv,s[j]);
            sum += len - maxv, minv = min(minv,maxv);

            for(int j = 0; j<M; j++)
                for(int u = 0; u <len ; u++) {
                    int x = nums[u * k + i - 1], cost = len - s[x];
                    f[i][j] = min(f[i][j],f[i-1][j ^ x] + cost);
                }
        }
        return min(sum + minv, f[k][0]);
    }
};
