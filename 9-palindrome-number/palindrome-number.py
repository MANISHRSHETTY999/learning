class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x) == str(x)[::-1]

# Example usage:
solution = Solution()
print(solution.isPalindrome(121))   # Output: True
print(solution.isPalindrome(-121))  # Output: False
print(solution.isPalindrome(10))    # Output: False
