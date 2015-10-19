ops = ['+', '-', '*', '/', '^']
for _ in range(int(raw_input())):
    exp = raw_input()
    var = []
    op = []
    ans = []
    for ch in exp:
        if ch == '(':
            continue
        elif ch == ')':
            x = var.pop()
            y = var.pop()
            o = op.pop()
            var.append(y+x+o)
        elif ch in ops:
            op.append(ch)
        else:
            var.append(ch)
    print var[0]
