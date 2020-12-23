import functools
from sympy.ntheory.modular import crt
n = int(input())

d = [(int(x) if x.isdigit() else 0) for x in input().split(",")]

m = []
a = []

allnums = filter(lambda x: x, d)
N = functools.reduce(lambda a, b: a*b, allnums, 1)
for i in range(len(d)):
    num = d[i]
    if not num:
        continue
    m.append(num)
    aval = -i
    while aval < 0:
        aval += num
    a.append(aval)

print(crt(m, a)[0])