from typing import List, Tuple
from collections import defaultdict

def reconstruct_array(n: int, b: List[int]) -> Tuple[bool, List[int]]:
    dp = defaultdict(lambda: defaultdict(list))
    
    for a1 in range(1, 101):
        if any(a1 * a2 == b[0] for a2 in range(1, 101)):
            dp[1 << 0][a1] = [a1]
    
    for mask in range(1, 1 << (n - 1)):
        for last in range(1, 101):
            if dp[mask][last]:
                for i in range(n - 1):
                    if not (mask & (1 << i)):
                        for next_val in range(1, 101):
                            if last * next_val == b[i]:
                                new_mask = mask | (1 << i)
                                dp[new_mask][next_val] = dp[mask][last] + [next_val]
    
    for last in range(1, 101):
        if dp[(1 << (n - 1)) - 1][last]:
            return True, dp[(1 << (n - 1)) - 1][last]
    
    return False, []

def main():
    n = int(input())
    b = list(map(int, input().split()))
    
    success, result = reconstruct_array(n, b)
    
    if success:
        print("Yes")
        print(*result)
    else:
        print("No")

if __name__ == "__main__":
    main()