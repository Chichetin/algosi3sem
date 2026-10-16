from collections import deque
import sys
def is_paired(left: str, right: str):
    dictinoray = {
        "(" : ")",
        "{" : "}",
        "[" : "]"
    }

    if dictinoray[left] == right:
        return True
    return False

def main():
    st = deque()
    seq = input()
    for s in seq:
        if s in "({[":
            st.append(s)
        else:
            if len(st) == 0:
                print("no")
                return
            prev = st.pop()
            if not is_paired(prev, s):
                print("no")
                return

    if len(st) > 0:
        print("no")
        return
    print("yes")

if __name__ == '__main__':
    main()
