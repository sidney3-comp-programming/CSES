from math import *
from sys import *

def solve(n,x,weights):
    endings = [0]*(1<<n)
    starts = [0]*(1<<n)
    for s in range(1, 1<<n):
        base = n + 1
        ending = 0
        for person in range(n):
            if not ((1<<person) & s):
                continue
            
            if weights[person] + endings[person] <= x:
                pass

if __name__ == "__main__":
    '''
    Fix that we are going to accept the first element (he must be in SOME elevator!)

    And then consider all subsets of the array -> take the one with the closest value to x that is below
    it.
    '''
    n, x = [int(c) for c in stdin.readline().strip().split(' ')]
    weights = [int(c) for c in stdin.readline().strip().split(' ')]
    solve(n,x,weights)