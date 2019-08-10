'''
最小滑动窗口子字符串
'''
import sys
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        res = ""
        table = [0]*128
        cnt,left = 0,0
        maxValue = sys.maxsize
        for i in range(len(t)):
            table[ord(t[i])] += 1
        for i in range(len(s)):
            table[ord(s[i])] -= 1
            if table[ord(s[i])] >= 0:
                cnt += 1
            while cnt == len(t):
                if maxValue > i-left+1:
                    maxValue = i-left+1
                    res = s[left:left+maxValue]
                    print(res)
                table[ord(s[left])] += 1
                if (table[ord(s[left])] > 0):
                    cnt -= 1
                left += 1

        return res

solution = Solution()
s = "ADOBECODEBANC"
t = 'ABC'
print(solution.minWindow(s, t))
