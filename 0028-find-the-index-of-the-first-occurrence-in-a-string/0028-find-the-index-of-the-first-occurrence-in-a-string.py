class Solution:
    def strStr(self, s: str, needle: str) -> int:

        sample = ""

        if len(needle) > len(s):
            return -1

        for i in range(len(needle)):
            sample += s[i]

        if sample == needle:
            return 0

        l = 0
        r = len(sample) - 1

        while r < len(s):

            sample = sample[1:]
            l += 1
            r += 1

            if r == len(s):
                break

            sample += s[r]

            if sample == needle:
                return l

        return -1