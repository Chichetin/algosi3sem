from math import inf


def main():
    l = list(map(int, input().split()))
    l0 = [x for x in l if x % 3 == 0]
    l1 = [x for x in l if x % 3 == 1]
    l2 = [x for x in l if x % 3 == 2]

    # l0.sort(reverse=True) не нужно, потому что мы сразу все добавим
    l1.sort()
    l2.sort()

    sm = sum(l0) + sum(l1) + sum(l2)
    if sm % 3 == 1:
        a = l1[0] if len(l1) > 0 else inf
        b = l2[0] + l2[1] if len(l2) > 1 else inf
        sm -= min(a, b)
    elif sm % 3 == 2:
        a = l1[0] + l1[1] if len(l1) > 1 else inf
        b = l2[0] if len(l2) > 0 else inf
        sm -= min(a, b)


    print(sm)
    # print(sum(l1) + (sum(l2) if len(l2) % 2 == 0 else sum(l2[:-1])))
    return


main()
