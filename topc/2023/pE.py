import random
import sys
sys.setrecursionlimit(50000000)

MAX_VAL = 2**20 - 1

def generate_test_case():
    a = random.randint(MAX_VAL - 100000, MAX_VAL)
    b = random.randint(MAX_VAL - 100000, MAX_VAL)
    m = random.randint(1, MAX_VAL)

    return a, b, m

def fast_pow(a, n, m, memo={}):
    if (a, n, m) in memo:
        return memo[(a, n, m)]

    if n == 0:
        return 1 % m
    if n == 1:
        return a % m

    if n % 2 == 0:
        tmp = fast_pow(a, n // 2, m, memo)
        result = (tmp * tmp - 2) % m
    else:
        result = (a * fast_pow(a, n-1, m, memo) - fast_pow(a, n-2, m, memo)) % m

    memo[(a, n, m)] = result
    return result



def test(a, b, m):
    if b == 1:
        return a % m
    a1 = a
    a2 = (a * a - 2 + m) % m

    for _ in range(2, b):
        a3 = (a2 * a - a1 + m) % m
        a1 = a2
        a2 = a3

    return a2

a, b, m = map(int, input().split())
print(fast_pow(a, b, m))