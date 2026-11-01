
n = int(input())
dct = dict()
for _ in range(n):
    s = tuple(sorted(input()))


    dct[s] = dct.get(s, 0) + 1
print(len(dct.keys()), max(dct.values()))
