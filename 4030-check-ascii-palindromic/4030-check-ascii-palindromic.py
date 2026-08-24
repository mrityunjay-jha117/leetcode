class Solution:
    def isPalindromic(self, s: str) -> bool:
        b = "".join(format(ord(c), '08b') for c in s)
        return b == b[::-1]