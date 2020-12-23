import re
n = int(input())
masks = ""
d = {}


def vad(s):
    final = []
    if s.find("X") == -1:
        return [s]
    for adr in vad(s.replace('X', '0', 1)):
        final.append(adr)
    for adr in vad(s.replace('X', '1', 1)):
        final.append(adr)
    return final

def apply(s, mask):
    #print(s)
    #print(mask)
    res = list(s)
    for i in range(len(mask)):
        if mask[i] == "1":
            res[i] = "1"
        if masks[i] == "X":
            res[i] = "X"

    return "".join(res)

for i in range(n):
    inp = input()
    if inp[1] == 'a':
        # mask
        masks = inp.split('=')[1].strip()
        #print(vad(masks))
    else:
        index = apply('{0:036b}'.format(int(re.search("\d+", inp).group(0))), masks)
        value = int(inp.split("=")[1].strip()) # string
        for adr in vad(index):
            # for each submask
            d[adr] = value

s = 0
for key in d.keys():
    s += d[key]
    #print(key)
    #print(d[key])

print(s)
