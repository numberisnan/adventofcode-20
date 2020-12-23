n = 936

m = 0
s = set()
for i in range(1024):
    s.add(i)

for i in range(n):
    v = int(input().replace("B", "1").replace("F", "0").replace("R", "1").replace("L", "0"), base=2)
    s.remove(v)

print(s)