import re
n = int(input())

d = {}
for i in range(n):

    q = re.sub(",|\.|bags?\.?|contain", "", input())
    if re.match(".*no other.*", q):
        pass
    else:
        c = re.split("(\d+)",q)
        to = c[0].strip()
        frm = []
        for ind in range(1,len(c),2):
            # add dic ent
            num = c[ind]
            s = c[ind+1]
            if to in d:
                d[to].append((num + s).strip())
            else:
                d[to] = [(num + s).strip()]

def search(st):
    if st not in d:
        return 1
    intc = 0
    for nex in d[st]:
        amt = int(nex.split()[0]) * search(" ".join(nex.split()[1:]))
        intc += amt
    return intc + 1


print(search("shiny gold")-1)
