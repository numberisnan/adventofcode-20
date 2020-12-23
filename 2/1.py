n = int(input())
count = 0


def parse(s):
    a = s.split()
    a[0] = a[0].split("-")
    a[0][1] = int(a[0][1])
    a[0][0] = int(a[0][0])
    return a


for i in range(n):
    s = input().split(":")
    a = parse(s[0])
    if (s[1][a[0][0]] == a[1] or s[1][a[0][1]] == a[1]) and s[1][a[0][0]] != s[1][a[0][1]]:
        count += 1


print(count)