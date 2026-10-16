def quick_pow(a, n):
    if n == 0:
        return 1
    if n < 0:
        return 1 / quick_pow(a, -n)
    half = quick_pow(a, n // 2)
    half *= half
    return half * a if n % 2 else half


def main():
    s = input().strip()
    a = int(s) if s.lstrip('-').isdigit() else float(s)
    n = int(input())
    print(quick_pow(a, n))


if __name__ == '__main__':
    main()