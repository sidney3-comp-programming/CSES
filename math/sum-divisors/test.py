from math import floor
from collections import defaultdict
def print_qs():
    N = 1006 
    val_ct = defaultdict(int)
    for d in range(1, N + 1):
        q = floor(N / d)
        val_ct[q] += 1
    for q, q_ct in val_ct.items():
        print(q, q_ct)

if __name__ == "__main__":
    print_qs()
