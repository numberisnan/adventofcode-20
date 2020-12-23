n = int(input())


def evaluate(e):
    if len(e) == 1:
        return int(e)

    plusindex = -1
    mulindex = -1
    i = len(e)
    level = 0

    while i >= 0:
        i -= 1
        if e[i] == ')':
            level += 1
        elif e[i] == '(':
            level -= 1
        elif e[i] == '+' and plusindex == -1 and not level:
            plusindex = i
        elif e[i] == '*' and mulindex == -1 and not level:
            mulindex = i

    #print(plusindex)
    #print(mulindex)

    if plusindex != -1 or mulindex != -1:
        if mulindex != -1:
            return evaluate(e[:mulindex]) * evaluate(e[mulindex+1:])
        else:
            return evaluate(e[:plusindex]) + evaluate(e[plusindex+1:])
    else:
        # start of parenthesis
        # find first parenthesis
        return evaluate(e[1:-1])


sum = 0
for i in range(n):
    equation = input().replace(" ", "")
    #print(equation)
    sum += evaluate(equation)

print(sum)
#st = "(5 * 4 + 7 + 4 + 8) + 9 * ((5 * 4) + 2 + (6 + 2 + 8 + 7 + 4 + 5)) * 5".replace(" ", "")
#print(evaluate(st))


