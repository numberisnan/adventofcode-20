import re

[r, n] = [int(x) for x in input().split()]
allCombs = set()
rulegraph = [[]] * 200

for i in range(r):
    inp = input()
    rulenum = int(inp.split(":")[0])
    findletter = re.findall("\"\w\"",inp)
    if len(findletter):
        rulegraph[rulenum] = [findletter[0][1:-1]]
    else:
        rulelist = [x.strip() for x in re.findall("[ \d\|]+", inp)[1].split("|")]
        converted = []
        #print(rulelist)
        for rule in rulelist:
            converted.append([int(x) for x in rule.split()])
        rulegraph[rulenum] = converted

def matches(s, rn):
    #print(s + " " + str(rn))
    for possibleRule in rulegraph[rn]:
        if isinstance(possibleRule, list):
            # recursive definition
            startpointer = 0
            fullmatch = True
            for placement in possibleRule:
                endpointer = startpointer
                match = False
                # a given rule might need more than 1 character, try all substrings starting at 0
                while (not match) and (endpointer < len(s)):
                    match = matches(s[startpointer:endpointer+1], placement)
                    endpointer += 1
                if match:
                    startpointer = endpointer
                else:
                    #cannot possible follow this set of rules
                    fullmatch = False
                    break
            if fullmatch:
                return True
        else:
            return s == possibleRule
    return False


sum = 0
for i in range(n):
    inp = input()
    print(matches(inp, 0))
    if matches(inp, 0):
        sum += 1

print(sum)

#print(matches("abbbbbbbbbbbbbbbbbbbbbb", 0))
