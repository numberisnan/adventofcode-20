import re
[t, n] = [int(x) for x in input().split()]

ranges = []


def parseRange(s):
    rs = s.split("-")
    return list(map(lambda s: int(s), rs))

def inrange(num, range):
    return range[0] <= num <= range[1]

for i in range(t):
    inp = input()
    rs = re.findall("\d+-\d+", inp)
    ranges.append([parseRange(rs[0]), parseRange(rs[1])])

# my ticket
input()
myticket = [int(x) for x in input().split(",")]

# construct error matrix
e = [] # first number is order of ranges, second is order in tickets
for i in range(len(ranges)):
    e.append([True] * len(ranges))


for i in range(n):
    ticket = [int(x) for x in input().split(",")]
    # check if ticket is valid
    isvalid = True
    for num in ticket:
        flag = True
        for rs in ranges:
            if inrange(num, rs[0]) or inrange(num, rs[1]):
                flag = False
        if flag:
            # error ticket
            isvalid = False
            break
    if not isvalid:
        continue

    for ni in range(len(ticket)):
        num = ticket[ni]
        for ri in range(len(ranges)):
            r = ranges[ri]
            if not (inrange(num, r[0]) or inrange(num, r[1])):
                e[ri][ni] = False
                #print("Field number " + str(ri) + " cannot be ticket field number " + str(ni) + " because of ticket number " + str(i) + " : " + str(num))

for l in e:
    for b in l:
        if b:
            print("1 ", end="")
        else:
            print("0 ", end="")
    print("")
print(myticket[10]*myticket[8]*myticket[18]*myticket[5]*myticket[14]*myticket[2])