from sys import *
memo = {}
MOD = int(1e9 + 7)
def backtrack(i,j):
    if (i,j) in memo:
        return memo[(i,j)]
    if j == 0:
        return 1
    if i <= 0 or j < 0:
        return 0
    memo[(i,j)] = backtrack(i - 1, j) + backtrack(i - 1, j - i)
    return memo[(i,j)]
def solve(n):  
    if not (n%4 == 0 or (n+1)%4 == 0):
        print(0)
        return
    else:
        target = n*(n+1)/4
        print((backtrack(n, target) * pow(2, MOD - 2, MOD))  % MOD)
        return
if __name__ == "__main__":
    n = int(stdin.readline().strip())
    solve(n)
