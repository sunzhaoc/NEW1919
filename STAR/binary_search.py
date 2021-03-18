'''
Description: 二分查找的例程 
Version: 1.0
Autor: Vicro
Date: 2021-01-06 14:32:50
LastEditTime: 2021-03-18 15:40:00
FilePath: \Leetcode\STAR\binary_search.py
'''

class Soulution:
    def binary_search01(self, x, target):
        '''
        description: 原始的二分查找。
        用于判断x中是否包含target，至于是哪一个，不重要。
        param {*}
        return {*}
        '''
        l, r = 0, len(x) - 1
        
        while l <= r:
            mid = (r - l) // 2 + l
            if target == x[mid]: return mid
            elif x[mid] > target:
                r = mid - 1
            elif x[mid] < target:
                l = mid + 1
        return -1


    def binary_searchLeft(self, x, target):
        '''
        description: 左边界的位置。找大于某数折最小值。
        param {*}
        return {*}
        '''
        l, r = 0, len(x) - 1
        
        while l < r:
            mid = (r - l) // 2 + l # 取靠左边的值
            if x[mid] >= target: # 始终保持right指向target，left持续逼近。
                r = mid
            elif x[mid] < target:
                l = mid + 1
        if x[l] == target: # 
            return l
        return -1


    def binary_searchRight(self, x, target):
        '''
        description: 右边界的位置
        param {*}
        return {*}
        '''
        l, r = 0, len(x) - 1
        while l < r:
            mid = (l + r + 1) // 2 # 取靠右边的值
            if x[mid] > target:
                r = mid - 1
            elif x[mid] <= target: # 始终保持left指向target，right向左逼近。
                l = mid
        if x[r] == target:
            return r
        return -1
            
sol = Soulution()
# ans = sol.binary_searchLeft([1, 2, 2, 2, 4, 8, 10], 2)
ans = sol.binary_searchRight([1, 2, 2, 2, 4, 8, 10], 2)
print(ans)