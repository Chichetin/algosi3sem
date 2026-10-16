from collections import deque

st = deque()

evaluation = input().split()

for s in evaluation:
    if s == "*":
        st.append(st.pop() * st.pop())
    elif s == "-":
        st.append(-st.pop() + st.pop())
    elif s == "+":
        st.append(st.pop() + st.pop())
    else:
        st.append(int(s))

print(st.pop())



