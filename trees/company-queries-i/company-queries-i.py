from sys import *
class CompanyQueries:
    def __init__(self, parents):
        # parse inputted true
        self.parents = parents
        self.cache = {}
    def query(self, node, levels):
        if (node, levels) in self.cache:
            return self.cache[(node, levels)]
        curr = node
        for _ in range(levels):
            if self.parents[curr - 1] == -1:
                self.cache[(node, levels)] = -1
                return -1
            curr = self.parents[curr - 1]
        self.cache[(node, levels)] = curr
        return curr

def solve():
    n,q = [int(c) for c in stdin.readline().strip().split(' ')]
    parents = [-1]*n # node[i] returns the parent of node i
    for i,x in enumerate([int(c) for c in stdin.readline().strip().split(' ')]):
        parents[i + 1] = x
    driver = CompanyQueries(parents)
    for _ in range(q):
        node, levels = [int(c) for c in stdin.readline().strip().split(' ')]
        print(driver.query(node, levels))
if __name__ == "__main__":
    solve()