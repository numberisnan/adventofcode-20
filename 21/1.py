import re
n = int(input())

allergenList = {}
counts = {}
all = set()
for i in range(n):
    recipe = input()
    ingredients = set(recipe.split("(")[0].split())
    allergens = set(recipe.split("(")[1][:-1].replace(",", "").split()[1:])
    all = all.union(ingredients)
    for ingredient in ingredients:
        if ingredient not in counts:
            counts[ingredient] = 1
        else:
            counts[ingredient] += 1
    for allergen in allergens:
        if allergen in allergenList:
            allergenList[allergen].append(ingredients)
        else:
            allergenList[allergen] = [ingredients]

safe = all
p = set()
for allergen in allergenList:
    possible = set()
    for ingredientList in allergenList[allergen]:
        if not len(possible):
            possible = ingredientList
        else:
            possible = possible & ingredientList
    print(allergen)
    print(possible)
    p = p.union(possible)
print(p)
total = 0
for ingredient in safe:
    total += counts[ingredient]

print(total)