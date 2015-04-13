val_dict = {'1':1, 'i':2, 'j':3, 'k':4}

def mul(x, y):
    prod_dict = {
                    1: {1:1, 2:2, 3:3, 4:4},
                    2: {1:2, 2:-1, 3:4, 4:-3},
                    3: {1:3, 2:-4, 3:-1, 4:2},
                    4: {1:4, 2:3, 3:-2, 4:-1}
                }
    return prod_dict[x][y]

def evaluate(expr):
    ''' Evaluates the quaternion product passed'''
    if len(expr) == 1:
        return [expr[0]]
    elif len(expr) == 0:
        return []
    prod = mul(expr[0], expr[1])
    mat = [expr[0], prod]
    for i in expr[2:]:
        if prod < 0:
            prod = -1 * mul(abs(prod),i)
        else:
            prod = mul(prod, i)
        mat.append(prod)
    return mat


def reverse_multiply(expr):
    if len(expr) == 1:
        return [expr[0]]
    prod = mul(expr[-2], expr[-1])
    mat = [prod, expr[-1]]
    for i in expr[-3::-1]:
        if prod < 0:
            prod = -1 * mul(i, abs(prod))
        else:
            prod = mul(i, prod)
        mat.insert(0, prod)
    return mat

terms = int(raw_input())
for case in range(1, terms+1):
    l, rep = map(int, raw_input().split())
    expr = raw_input()
    repeated = expr * rep
    repeated = map(lambda x: val_dict[x], repeated)
    ps = evaluate(repeated)
    rps = reverse_multiply(repeated)
    valis = [index for index, x in enumerate(ps) if x == 2]
    valks = [index for index, x in enumerate(rps) if x == 4]
    # print (valis, valks)
    flag = False
    for begin in valis:
        for end in valks:
            # print (begin, end)
            if 3 in evaluate(repeated[begin+1:end]):
                flag = True
                break
    ans = "YES" if flag else "NO"
    print "Case #%s: %s" % (case, ans)
