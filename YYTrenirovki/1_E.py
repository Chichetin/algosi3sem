# 1+(2*2 - 3)  ->  2
#
# expr   := term {(+|-) term}
# term   := factor {* factor}
# factor := [-|+] factor | number | ( expr )

tokens = []
pos = 0
wrong = False


def tokenize(seq: str):
    res = []
    i = 0
    while i < len(seq):
        s = seq[i]
        if s == " ":
            i += 1
        elif s.isdigit():
            num = ""
            while i < len(seq) and seq[i].isdigit():
                num = num + seq[i]
                i += 1
            res.append(num)
        elif s in "+-*()":
            res.append(s)
            i += 1
        else:
            return None  # посторонний символ
    return res


def peek():
    return tokens[pos] if pos < len(tokens) else ""


def parse_expr():
    global pos
    res = parse_term()
    while peek() == "+" or peek() == "-":
        op = tokens[pos]
        pos += 1
        if op == "+":
            res = res + parse_term()
        else:
            res = res - parse_term()
    return res


def parse_term():
    global pos
    res = parse_factor()
    while peek() == "*":
        pos += 1
        res = res * parse_factor()
    return res


def parse_factor():
    global pos, wrong
    s = peek()
    if s == "-":
        pos += 1
        return -parse_factor()
    if s == "+":
        pos += 1
        return parse_factor()
    if s == "(":
        pos += 1
        res = parse_expr()
        if peek() != ")":
            wrong = True
            return 0
        pos += 1
        return res
    if s.isdigit():
        pos += 1
        return int(s)
    wrong = True
    return 0


def main():
    global tokens
    seq = input()
    tokens = tokenize(seq)
    if tokens is None:
        print("WRONG")
        return

    res = parse_expr()
    # если разобрали не все токены, значит лишние числа или скобки - "1 1 + 2"
    if wrong or pos != len(tokens):
        print("WRONG")
        return
    print(res)


if __name__ == '__main__':
    main()
