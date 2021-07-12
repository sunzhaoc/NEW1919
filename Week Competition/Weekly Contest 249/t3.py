'''
Description: 
Version: 1.0
Autor: 冰凝水
Date: 2021-04-25 10:18:02
LastEditTime: 2021-07-11 11:52:19
FilePath: \Leetcode\Week Competition\Weekly Contest 249\t3.py
'''

"""
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ██姜██━██狗██ ┃+
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
"""
from collections import defaultdict
class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:

        def get_digits(i):
            first = i//(3**2)
            second = (i//3) % 3
            third = i % 3
            return [first, second, third]

        def valid(i):
            digits = get_digits(i)
            if digits[0] != digits[1] and digits[1] != digits[2]:
                return True
            return False

        def check_stack_valid(i, j):
            i_digits = get_digits(i)
            j_digits = get_digits(j)
            for i in range(3):
                if i_digits[i] == j_digits[i]:
                    return False
            return True

        valids = [i for i in range(pow(m, 3)) if valid(i)]
        valid_trans = defaultdict(list)
        for i in valids:
            for j in valids:
                if check_stack_valid(i, j):
                    valid_trans[i].append(j)

        cur = Counter(valids)
        mod = 10**9 + 7

        def transition(counts):
            output = defaultdict(int)
            for k in counts:
                v = counts[k]
                for val in valid_trans[k]:
                    output[val] += v % mod

            return output

        for i in range(n-1):
            cur = transition(cur)

        res = sum(cur.values()) % mod
        return res

sol = Solution()
ans = sol.colorTheGrid(4, 1)
print(ans)
