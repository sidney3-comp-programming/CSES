from sys import stdin

def solve(vals):
    cubes = []
    for v in vals:
        if not cubes or cubes[-1] <= v:
            cubes.append(v)
        else:
            pos = cubes.bisect_right(vals, v)
            if pos != len(vals):
                cubes[pos] = v
    return len(cubes)

if __name__ == "__main__":
    numVals = int(stdin.readline().strip())
    vals = [int(c) for c in stdin.readline().strip().split(' ')]
    print(solve(vals))