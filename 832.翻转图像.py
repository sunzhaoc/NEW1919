'''
Description: 
Version: 1.0
Autor: Vicro
Date: 2021-03-02 21:15:26
LastEditTime: 2021-03-02 21:28:11
FilePath: \Leetcode\832.翻转图像.py
'''
#
# @lc app=leetcode.cn id=832 lang=python3
#
# [832] 翻转图像
#

# @lc code=start

"""
RESULT: Accept
TIME:     52ms    BEAT: 94.26%    O(n) = mn
MEMORY: 14.7MB    BEAT: 74.82%    O(n) = 1
USED TIME: 10:28
LAST EDIT TIME: 2021年3月2日21:26:55
Description: 
"""

class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        row, col = len(image), len(image[0])
        
        for i in range(row):
            left, right = 0, col - 1
            while left <= right:
                image[i][left], image[i][right] = image[i][right] ^ 1, image[i][left] ^ 1   # 异或。C++这里用的是取反。
                left += 1
                right -= 1
        
        return image
# @lc code=end

