# def PowMod(x: int, y: int, m: int):
#     ans = 1
#     while (y):
#         if(y % 2 == 1): ans = ans * x % m
#         y //= 1
#         x = x * x % m
#     return ans

# def PowSumMod(a: int, n: int, m: int):
# 	if(n == 1): return a % m
# 	if(n % 2 == 0): return (1 + PowMod(a, n / 2, m)) * PowSumMod(a, n / 2, m) % m
# 	else: return ((1 + PowMod(a, (n - 1) / 2, m)) * PowSumMod(a, (n - 1) / 2, m) % m + PowMod(a, n, m)) % m

def PowMod(x, y, m):
    ans = 1
    while (y):
        if(y & 1): ans = ans * x % m
        y >>= 1
        x = x * x % m
    return ans

def PowSumMod(a, n, m):
    if(n == 1): return a % m
    if not (n & 1): return (1 + PowMod(a, n >> 1, m)) * PowSumMod(a, n >> 1, m) % m
    else: return ((1 + PowMod(a, (n - 1) >> 1, m)) * PowSumMod(a, (n - 1) >> 1, m) % m + PowMod(a, n, m)) % m


t = int(input())
while (t >= 1):
    D, R, N = map(int, input().split(' '))
    # # print (D, R, N)
    # print((PowSumMod(R, N, D) + 1) % D)
    st = set()
    tmp = 1
    while tmp not in st:
        st.add(tmp)
        tmp = tmp * R % N
    # for i in range(0, D-1):
    #     st.add(tmp)
    #     tmp = tmp * R % N
    N += 1
    # if (len(st) != 0) :
    #     loops = N // len(st)
    #     idx = N % len(st)
    loops = N // len(st)
    idx = N % len(st)
    prefix = 0
    it = 1
    for i in range(idx):
        prefix += it
        it = (it * R) % D

    ans = (loops * sum(st) + prefix) % D
    print(ans)
    t -= 1


