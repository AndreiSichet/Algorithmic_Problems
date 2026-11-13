class Solution:
    def findValid(self, s: str, pointer: int) -> tuple[str | None, int]:
        skip = 0
        while pointer >= 0:
            if s[pointer] == '#':
                skip += 1
            elif skip > 0:
                skip -= 1
            else:
                return s[pointer], pointer-1
            pointer -= 1
        return None, pointer
    def backspaceCompare(self, s: str, t: str) -> bool:
        first = len(s) - 1
        second = len(t) - 1
        while True:
            char1, first = self.findValid(s, first)
            char2, second = self.findValid(t, second)
            if char1 != char2:
                return False
            if char1 is None:
                return True